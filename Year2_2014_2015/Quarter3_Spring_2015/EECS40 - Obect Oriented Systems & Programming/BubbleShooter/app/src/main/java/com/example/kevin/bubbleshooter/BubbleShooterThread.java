package com.example.kevin.bubbleshooter;

/**+
 * Created by
 *      Kevin Ngo (25092065)
 *      Jack Melcher (67574625)
 *      on 4/3/2015.
 */

import android.app.Activity;
import android.graphics.Canvas;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceHolder;

public class BubbleShooterThread extends Thread {
    BubbleShooterView bsv ;

    public BubbleShooterThread ( BubbleShooterView bsv ) {
        this . bsv = bsv ;
    }

    public void run () {
        SurfaceHolder sh = bsv . getHolder () ;

        // Main game loop .
        while ( ! Thread . interrupted () ) {
            Canvas c = sh . lockCanvas ( null ) ;
            try {
                synchronized ( sh ) {
                    bsv . advanceFrame ( c ) ;
                }
            } catch ( Exception e ) {
            } finally {
                if ( c != null ) {
                    sh . unlockCanvasAndPost ( c ) ;
                }
            }
            // Set the frame rate by setting this delay
            try {
                Thread . sleep (30) ;
            } catch ( InterruptedException e ) {
            // Thread was interrupted while sleeping .
                return ;
            }
        }
    }
}
