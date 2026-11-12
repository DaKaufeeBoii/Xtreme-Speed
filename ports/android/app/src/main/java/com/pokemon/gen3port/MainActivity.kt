package com.pokemon.gen3port

import android.os.Bundle
import android.opengl.GLSurfaceView
import android.view.View
import android.view.WindowInsets
import android.view.WindowInsetsController
import android.widget.FrameLayout
import androidx.appcompat.app.AppCompatActivity
import java.io.File
import java.io.FileOutputStream
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MainActivity : AppCompatActivity(), GLSurfaceView.Renderer {

    companion object {
        init {
            System.loadLibrary("pokegen3")
        }
    }

    private external fun nativeInit(biosPath: String, romPath: String)
    private external fun nativeInitGL()
    private external fun nativeRenderFrame()
    private external fun nativeSetInput(keyMask: Int)
    private external fun nativeSelectGame(gameType: Int)
    private external fun nativeTransferRegion(targetRegion: Int, downscale: Boolean)
    private external fun nativeDebugHeal()
    private external fun nativeDestroy()

    private lateinit var glSurfaceView: GLSurfaceView
    private lateinit var touchOverlay: TouchOverlayView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        hideSystemUI()

        val root = FrameLayout(this)

        glSurfaceView = GLSurfaceView(this).apply {
            setEGLContextClientVersion(3)
            setRenderer(this@MainActivity)
            renderMode = GLSurfaceView.RENDERMODE_CONTINUOUSLY
        }
        root.addView(glSurfaceView)

        touchOverlay = TouchOverlayView(this).apply {
            onInputChanged = { mask ->
                nativeSetInput(mask)
            }
            onDebugClicked = {
                nativeDebugHeal()
            }
            onFerryClicked = {
                nativeTransferRegion(1, true) // Sail to Kanto with auto-downscale
            }
        }
        root.addView(touchOverlay)

        setContentView(root)

        // Setup internal asset files
        val biosFile = extractAsset("gba_bios.bin")
        val romFile = extractAsset("pokemon-emerald.gba")

        nativeInit(biosFile.absolutePath, romFile.absolutePath)
    }

    private fun extractAsset(name: String): File {
        val outFile = File(filesDir, name)
        if (!outFile.exists()) {
            try {
                assets.open(name).use { input ->
                    FileOutputStream(outFile).use { output ->
                        input.copyTo(output)
                    }
                }
            } catch (_: Exception) {}
        }
        return outFile
    }

    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        nativeInitGL()
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        // GLES viewport handled natively for 20:9 True Widescreen
    }

    override fun onDrawFrame(gl: GL10?) {
        nativeRenderFrame()
    }

    private fun hideSystemUI() {
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.R) {
            window.insetsController?.let {
                it.hide(WindowInsets.Type.statusBars() or WindowInsets.Type.navigationBars())
                it.systemBarsBehavior = WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE
            }
        } else {
            @Suppress("DEPRECATION")
            window.decorView.systemUiVisibility = (
                View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                or View.SYSTEM_UI_FLAG_FULLSCREEN
                or View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                or View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                or View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                or View.SYSTEM_UI_FLAG_LAYOUT_STABLE
            )
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        nativeDestroy()
    }
}
