package info.kngo.dash_till_puff;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.Random;

/**
 * Created by Kevin on 4/19/2015.
 */
public class DashTillPuffSurfaceView extends SurfaceView implements SurfaceHolder . Callback , TimeConscious {

    private DashTillPuffRenderThread renderThread;

    //Game Object variables
    private SpaceShip spaceship;
    private Background background1;
    private Background background2;
    public Trajectory trajectory;
    private CosmicFactory cosmicfactory;

    //Game state
    boolean gameState = false;
    //Game score
    int gameScore = 0;


    public DashTillPuffSurfaceView ( Context context ) {
        super ( context ) ;
        getHolder () . addCallback ( this ) ;
        setFocusable ( true ) ;
    }

    @Override
    public void surfaceCreated ( SurfaceHolder holder ) {

        // Launch animator thread .
        renderThread = new DashTillPuffRenderThread ( this ) ;
        renderThread . start () ;

        // Create the sliding background , cosmic factory , trajectory
        // and the space ship
        spaceship = new SpaceShip(this, getWidth()/3 - 64, getHeight()/2 - 64, getWidth()/3 + 64, getHeight()/2 + 64);
        background1 = new Background(this, 0, 0, getWidth(), getHeight());
        background2 = new Background(this, getWidth(), 0, 2*getWidth(), getHeight());
        trajectory = new Trajectory(this);
        cosmicfactory = new CosmicFactory(this);
    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int format, int width, int height) {
        // Respond to surface changes , e . g . , aspect ratio changes .
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {
        // The cleanest way to stop a thread is by interrupting it .
        // DashTillPuffRenderThread regularly checks its interrupt flag .
        renderThread.interrupt() ;
    }

    @Override
    public boolean onTouchEvent ( MotionEvent e ) {
        switch ( e . getAction () ) {
            case MotionEvent . ACTION_DOWN : // Thrust the space ship up .

                //Increase the velocity of the spaceship
                spaceship.mAcceleration = -2;
                gameState = true;

                break ;
            case MotionEvent . ACTION_UP : // Let space ship fall freely .

                //Lower the velocity of the spaceship
                spaceship.mAcceleration = 2;

                break ;
        }
        return true ;
    }

    @Override
    public void onDraw ( Canvas c ) {
        super . onDraw ( c ) ;
        // Draw everything ( restricted to the displayed rectangle ) .
    }

    @Override
    public void tick ( Canvas c ) {
        // Tick background , space ship , cosmic factory , and trajectory .
        // Draw everything ( restricted to the displayed rectangle ) .
        Paint paint = new Paint();

        //Collision Detection
        if(!cosmicfactory.cluster.isEmpty()) {
            for (int i = 0; i < cosmicfactory.cluster.size(); i++) {
                int x1 = spaceship.mX1, x2 = spaceship.mX2;
                int y1 = spaceship.mY1, y2 = spaceship.mY2;
                int a1 = cosmicfactory.cluster.get(i).mX1, a2 = cosmicfactory.cluster.get(i).mX2;
                int b1 = cosmicfactory.cluster.get(i).mY1, b2 = cosmicfactory.cluster.get(i).mY2;
                /*
                if ((a2 >= x1 && b2 >= y1) || (a1 <= x2 && b2 >= y1) || (a2 >= x1 && b1 <= y2) || (a1 <= x2 && b1 <= y2)) {
                    spaceship.mAlpha = 0;
                }
                */
                if(a1 >= x1 && a1 <= x2 && b1 >= y1 && b1 <= y2){
                    spaceship.mAlpha = 0;
                }
                if(a2 >= x1 && a2 <= x2 && b2 >= y1 && b2 <= y2){
                    spaceship.mAlpha = 0;
                }
                if(a1 >= x1 && a1 <= x2 && b2 >= y1 && b2 <= y2){
                    spaceship.mAlpha = 0;
                }
                if(a2 >= x1 && a2 <= x2 && b1 >= y1 && b1 <= y2){
                    spaceship.mAlpha = 0;
                }
            }
        }

        //Draw scrolling background
        if(background1 != null){
           background1.tick(c);
        }
        if(background2 != null){
            background2.tick(c);
        }
        if(!gameState){
            paint.setTextSize(65);
            paint.setColor(Color.WHITE);
            c.drawText("Tap anywhere to start the game", getWidth()/2, getHeight()/2, paint);
        }
        if(gameState) {
            //Draw trajectory line
            if (trajectory != null) {
                trajectory.tick(c);
            }
            //Draw SpaceShip
            if (spaceship != null) {
                spaceship.tick(c);
            }
            paint.setTextSize(100);
            paint.setColor(Color.WHITE);
            c.drawText(""+gameScore, 0, 100, paint);
            //Spawn and Draw Cosmic Objects
            if(cosmicfactory != null) {
                cosmicfactory.tick(c);
            }
            //Increment Game Score
            gameScore++;
        }
        //Restart the game
        if(spaceship.mAlpha <= 0){
            gameState = false;
            gameScore = 0;
            trajectory.points.clear();
            cosmicfactory.cluster.clear();
            spaceship = new SpaceShip(this, getWidth()/3 - 64, getHeight()/2 - 64, getWidth()/3 + 64, getHeight()/2 + 64);
        }
    }
}

