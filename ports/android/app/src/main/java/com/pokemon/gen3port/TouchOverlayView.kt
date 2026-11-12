package com.pokemon.gen3port

import android.content.Context
import android.graphics.*
import android.util.AttributeSet
import android.view.MotionEvent
import android.view.View
import kotlin.math.*

class TouchOverlayView @JvmOverloads constructor(
    context: Context,
    attrs: AttributeSet? = null,
    defStyleAttr: Int = 0
) : View(context, attrs, defStyleAttr) {

    // Bitmasks matching pokegen3.h
    companion object {
        const val KEY_A      = 1 shl 0
        const val KEY_B      = 1 shl 1
        const val KEY_SELECT = 1 shl 2
        const val KEY_START  = 1 shl 3
        const val KEY_RIGHT  = 1 shl 4
        const val KEY_LEFT   = 1 shl 5
        const val KEY_UP     = 1 shl 6
        const val KEY_DOWN   = 1 shl 7
        const val KEY_R      = 1 shl 8
        const val KEY_L      = 1 shl 9
    }

    var onInputChanged: ((Int) -> Unit)? = null
    var onDebugClicked: (() -> Unit)? = null
    var onFerryClicked: (() -> Unit)? = null

    private var activeKeyMask = 0

    // Floating Dynamic Thumbstick State (Left Half)
    private var dpadPointerId = -1
    private var dpadAnchorX = 0f
    private var dpadAnchorY = 0f
    private var dpadThumbX = 0f
    private var dpadThumbY = 0f
    private var isDpadActive = false

    private val dpadMaxRadius = 130f
    private val dpadDeadzone = 30f

    // Action Buttons (Right Half)
    private val btnRadius = 75f

    // Paints
    private val basePaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
        color = Color.argb(80, 255, 255, 255)
        style = Paint.Style.STROKE
        strokeWidth = 6f
    }
    private val fillPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
        color = Color.argb(40, 255, 255, 255)
        style = Paint.Style.FILL
    }
    private val thumbPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
        color = Color.argb(160, 56, 189, 248) // Neon Cyan
        style = Paint.Style.FILL
    }
    private val textPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
        color = Color.WHITE
        textSize = 36f
        typeface = Typeface.DEFAULT_BOLD
        textAlign = Paint.Align.CENTER
    }

    override fun onDraw(canvas: Canvas) {
        super.onDraw(canvas)
        val w = width.toFloat()
        val h = height.toFloat()

        // 1. Draw Floating Dynamic D-Pad if Active
        if (isDpadActive) {
            canvas.drawCircle(dpadAnchorX, dpadAnchorY, dpadMaxRadius, fillPaint)
            canvas.drawCircle(dpadAnchorX, dpadAnchorY, dpadMaxRadius, basePaint)
            canvas.drawCircle(dpadThumbX, dpadThumbY, 45f, thumbPaint)
        }

        // 2. Draw A & B Action Buttons (Right Side)
        val btnAX = w - 110f
        val btnAY = h - 160f
        val btnBX = w - 240f
        val btnBY = h - 90f

        drawButton(canvas, btnAX, btnAY, btnRadius, "A", (activeKeyMask and KEY_A) != 0, Color.argb(140, 16, 185, 129))
        drawButton(canvas, btnBX, btnBY, btnRadius, "B", (activeKeyMask and KEY_B) != 0, Color.argb(140, 239, 68, 68))

        // 3. Draw Shoulder Triggers L & R
        drawPill(canvas, 90f, 60f, 130f, 60f, "L", (activeKeyMask and KEY_L) != 0)
        drawPill(canvas, w - 90f, 60f, 130f, 60f, "R", (activeKeyMask and KEY_R) != 0)

        // 4. Draw Start & Select (Top Center)
        drawPill(canvas, w / 2f - 90f, 55f, 110f, 50f, "SELECT", (activeKeyMask and KEY_SELECT) != 0)
        drawPill(canvas, w / 2f + 90f, 55f, 110f, 50f, "START", (activeKeyMask and KEY_START) != 0)
    }

    private fun drawButton(canvas: Canvas, cx: Float, cy: Float, radius: Float, label: String, pressed: Boolean, glowColor: Int) {
        fillPaint.color = if (pressed) glowColor else Color.argb(45, 255, 255, 255)
        canvas.drawCircle(cx, cy, radius, fillPaint)
        basePaint.color = if (pressed) Color.WHITE else Color.argb(100, 255, 255, 255)
        canvas.drawCircle(cx, cy, radius, basePaint)
        canvas.drawText(label, cx, cy + 12f, textPaint)
    }

    private fun drawPill(canvas: Canvas, cx: Float, cy: Float, w: Float, h: Float, label: String, pressed: Boolean) {
        val rect = RectF(cx - w / 2f, cy - h / 2f, cx + w / 2f, cy + h / 2f)
        fillPaint.color = if (pressed) Color.argb(140, 56, 189, 248) else Color.argb(40, 255, 255, 255)
        canvas.drawRoundRect(rect, 20f, 20f, fillPaint)
        basePaint.color = if (pressed) Color.WHITE else Color.argb(90, 255, 255, 255)
        canvas.drawRoundRect(rect, 20f, 20f, basePaint)
        canvas.drawText(label, cx, cy + 12f, textPaint)
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        val action = event.actionMasked
        val index = event.actionIndex
        val pointerId = event.getPointerId(index)
        val x = event.getX(index)
        val y = event.getY(index)

        val halfW = width / 2f

        when (action) {
            MotionEvent.ACTION_DOWN, MotionEvent.ACTION_POINTER_DOWN -> {
                if (x < halfW && dpadPointerId == -1) {
                    // Anchor Floating Dynamic Thumbstick right where the thumb lands!
                    dpadPointerId = pointerId
                    dpadAnchorX = x
                    dpadAnchorY = y
                    dpadThumbX = x
                    dpadThumbY = y
                    isDpadActive = true
                    HapticEngine.tick(context)
                } else {
                    handleButtonPress(x, y, true)
                }
            }
            MotionEvent.ACTION_MOVE -> {
                for (i in 0 until event.pointerCount) {
                    val pid = event.getPointerId(i)
                    val px = event.getX(i)
                    val py = event.getY(i)

                    if (pid == dpadPointerId) {
                        updateDpadPosition(px, py)
                    }
                }
            }
            MotionEvent.ACTION_UP, MotionEvent.ACTION_POINTER_UP, MotionEvent.ACTION_CANCEL -> {
                if (pointerId == dpadPointerId) {
                    dpadPointerId = -1
                    isDpadActive = false
                    // Release D-Pad bits
                    activeKeyMask = activeKeyMask and (KEY_UP or KEY_DOWN or KEY_LEFT or KEY_RIGHT).inv()
                    onInputChanged?.invoke(activeKeyMask)
                } else {
                    handleButtonPress(x, y, false)
                }
            }
        }

        invalidate()
        return true
    }

    private fun updateDpadPosition(px: Float, py: Float) {
        val dx = px - dpadAnchorX
        val dy = py - dpadAnchorY
        val dist = sqrt(dx * dx + dy * dy)

        // Clamp thumb position inside maximum radius
        if (dist <= dpadMaxRadius) {
            dpadThumbX = px
            dpadThumbY = py
        } else {
            dpadThumbX = dpadAnchorX + (dx / dist) * dpadMaxRadius
            dpadThumbY = dpadAnchorY + (dy / dist) * dpadMaxRadius
        }

        // Clear D-pad bits
        activeKeyMask = activeKeyMask and (KEY_UP or KEY_DOWN or KEY_LEFT or KEY_RIGHT).inv()

        if (dist > dpadDeadzone) {
            val angle = (atan2(dy.toDouble(), dx.toDouble()) * 180.0 / Math.PI + 360.0) % 360.0

            // 8-Way Dynamic D-Pad calculation
            if (angle in 22.5..157.5) activeKeyMask = activeKeyMask or KEY_DOWN
            if (angle in 112.5..247.5) activeKeyMask = activeKeyMask or KEY_LEFT
            if (angle in 202.5..337.5) activeKeyMask = activeKeyMask or KEY_UP
            if (angle >= 292.5 || angle <= 67.5) activeKeyMask = activeKeyMask or KEY_RIGHT
        }

        onInputChanged?.invoke(activeKeyMask)
    }

    private fun handleButtonPress(x: Float, y: Float, isDown: Boolean) {
        val w = width.toFloat()
        val h = height.toFloat()

        val btnAX = w - 110f
        val btnAY = h - 160f
        val btnBX = w - 240f
        val btnBY = h - 90f

        fun inDist(cx: Float, cy: Float, r: Float) = (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r

        var mask = 0
        if (inDist(btnAX, btnAY, btnRadius + 20f)) mask = mask or KEY_A
        if (inDist(btnBX, btnBY, btnRadius + 20f)) mask = mask or KEY_B
        if (x < 180f && y < 110f) mask = mask or KEY_L
        if (x > w - 180f && y < 110f) mask = mask or KEY_R
        if (x in (w / 2f - 150f)..(w / 2f - 20f) && y < 110f) mask = mask or KEY_SELECT
        if (x in (w / 2f + 20f)..(w / 2f + 150f) && y < 110f) mask = mask or KEY_START

        if (mask != 0) {
            activeKeyMask = if (isDown) (activeKeyMask or mask) else (activeKeyMask and mask.inv())
            if (isDown) HapticEngine.tick(context)
            onInputChanged?.invoke(activeKeyMask)
        }
    }
}
