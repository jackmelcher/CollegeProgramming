package info.kngo.dash_till_puff;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

/**
 * Created by Kevin on 4/19/2015.
 */
public class DashTillPuffRenderThread extends Thread {
    private final DashTillPuffSurfaceView view ;
    private static final int FRAME_PERIOD = 5; // In ms

    public DashTillPuffRenderThread ( DashTillPuffSurfaceView view ) {
        this . view = view ;
    }

    public void run () {
        SurfaceHolder sh = view . getHolder () ;
        // Main game loop .
        while ( ! Thread . interrupted () ) {
            Canvas c = sh . lockCanvas ( null ) ;
            try {
                synchronized ( sh ) {
                    view . tick ( c ) ;
                }
            } catch ( Exception e ) {
            } finally {
                if ( c != null ) {
                    sh . unlockCanvasAndPost ( c ) ;
                }
            }
            // Set the frame rate by setting this delay
            try {
                Thread . sleep ( FRAME_PERIOD ) ;
            } catch ( InterruptedException e ) {
                // Thread was interrupted while sleeping .
                return ;
            }
        }
    }
}