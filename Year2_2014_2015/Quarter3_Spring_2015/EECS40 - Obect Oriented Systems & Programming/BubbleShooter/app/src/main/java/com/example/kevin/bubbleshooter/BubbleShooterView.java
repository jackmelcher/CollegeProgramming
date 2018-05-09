package com.example.kevin.bubbleshooter;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.Random;
import java.lang.*;


/**+
 * Created by
 *      Kevin Ngo (25092065)
 *      Jack Melcher (67574625)
 *      on 4/3/2015.
 */
// This is the ‘‘ game engine ’ ’.
public class BubbleShooterView extends SurfaceView implements SurfaceHolder. Callback {

    private BubbleShooterThread bst;

    //Bubble that will be spawned throughout game
    private Bubble shooter;
    private BubbleArrow arrow;
    //Array of Bubble Objects
    private Bubble[][] bubbleArray = new Bubble[30][];
    //Colors
    private static int[] Colors = {
            Color.CYAN, Color.RED, Color.BLUE, Color.BLACK, Color.YELLOW, Color.GREEN, Color.MAGENTA, Color.GRAY
    };

    public BubbleShooterView ( Context context ) {
        super ( context ) ;
        // Notify the SurfaceHolder that you ’d like to receive
        // SurfaceHolder callbacks .

        getHolder () . addCallback(this) ;
        setFocusable ( true ) ;

        // Initialize game state variables . DON ’T RENDER THE GAME YET .
    }
    @Override
    public void surfaceCreated ( SurfaceHolder holder ) {
        // Construct game initial state ( bubbles , etc .)
        //Initializing the bubble array (Load 67 bubbles onto game screen)
        int x = getWidth()/20, y = getWidth()/20;
        int radius = getWidth()/20;
        int color;
        Random rand = new Random();
        //Create array rows
        for(int i = 0; i < bubbleArray.length; i++) {

                bubbleArray[i] = new Bubble[10];

        }
        //Fill with bubbles
        for(int i = 0; i < bubbleArray.length; i++) {
            for (int j = 0; j < bubbleArray[i].length; j++) {
                color = Colors[rand.nextInt(Colors.length)];
                bubbleArray[i][j] = new Bubble(this, x, y, color, radius);
                x += getWidth() / 10;
            }
            x =  getWidth()/20;
            y += getWidth() / 10;
            //Exit setup loop once half the screen is filled
            if((i+1)*getWidth() / 10 >= getHeight()/2){
                break;
            }
        }
        color = Colors[rand.nextInt(Colors.length)];
        shooter = new Bubble(this, getWidth()/2, getHeight()-radius, color, radius);
        arrow = new BubbleArrow(this, radius);
        // Launch animator thread .
        bst = new BubbleShooterThread ( this ) ;
        bst . start () ;
    }

    @Override
    public void surfaceChanged ( SurfaceHolder holder , int format , int width , int height ) {
        // Respond to surface changes , e . g . , aspect ratio changes .
    }

    @Override
    public void surfaceDestroyed ( SurfaceHolder holder ) {
        // The cleanest way to stop a thread is by interrupting it .
        // BubbleShooterThread regularly checks its interrupt flag .
        bst.interrupt() ;
    }

    @Override
    public void onDraw ( Canvas c ) {
        super . onDraw ( c ) ;
        renderGame ( c ) ;
    }

    @Override
    public boolean onTouchEvent ( MotionEvent e ) {
        // Update game state in response to events :
        // touch - down , touch - up , and touch - move .
        // Current finger position .
        int curX = (int) e . getX () ;
        int curY = (int) e . getY() ;
        double x1, y1, magnitude;
        switch ( e . getAction () ) {
            case MotionEvent . ACTION_DOWN :
                // Update Game State .
                if(curY < getHeight() - getWidth()/10) {
                    arrow.x2 = curX;
                    arrow.y2 = curY;
                }
                break ;
            case MotionEvent . ACTION_MOVE :
                // Update Game State .
                if(curY < getHeight() - getWidth()/10) {
                    arrow.x2 = curX;
                    arrow.y2 = curY;
                }
                break ;
            case MotionEvent. ACTION_UP :
                if(shooter.mVelX == 0 && shooter.mVelY == 0) {
                    // Update Game State .
                    if(curY < getHeight() - getWidth()/10) {
                        //Limits the velocity of the ball
                        x1 = (curX - getWidth() / 2);
                        y1 = (curY - getHeight() + getWidth() / 20);
                        magnitude = Math.sqrt((x1 * x1) + (y1 * y1));
                        shooter.mVelX = (80 * (x1 / magnitude));
                        shooter.mVelY = (80 * (y1 / magnitude));
                        break;
                    }
                }
        }
        return true ;
    }

    public void advanceFrame ( Canvas c ) {
        // Update game state to animate moving or exploding bubbles
        // ( e . g . , advance location of moving bubble ) .

        //Detect where the bubble can stop
        int screen_x_division = getWidth()/10, screen_y_division = getWidth()/10;
        int radius = getWidth()/20;
        int i = 0,j = 0;
        double predicted_x, predicted_y;
        int color;
        Random rand = new Random();


        //Check what's in front of the shot bubble
        if(shooter.mVelX != 0 || shooter.mVelY != 0) {
            //Reassign the predicted x and y values
            predicted_x = shooter.mVelX + shooter.mX;
            predicted_y = shooter.mVelY + shooter.mY;
            //Acquire index of bubble array based on predicted_y value
            for (int I = 0; I < bubbleArray.length; I++) {
                if (predicted_y > I * screen_y_division && predicted_y < (I + 1) * screen_y_division) {
                    i = I;
                    //Acquire index of bubble array based on predicted_x value
                    for (int J = 0; J < bubbleArray[i].length; J++) {
                        if (predicted_x > J * screen_x_division && predicted_x < (J + 1) * screen_x_division) {
                            j = J;
                            break;
                        }
                    }
                    break;
                }
            }

            //Check if that index in the bubble array is null at predicted movement location
            //Continue moving if null, Stop moving if false or bounces off ceiling
            if (shooter.mVelY > 0 || bubbleArray[i][j] != null) {
                shooter.mVelX = 0;
                shooter.mVelY = 0;
                //Acquire index of bubble array based on shooter.mY value
                for (int I = 0; I < bubbleArray.length; I++) {
                    if (shooter.mY > I * screen_y_division && shooter.mY < (I + 1) * screen_y_division) {
                        i = I;
                        shooter.mY = (I + 1) * screen_y_division - radius;
                        //Acquire index of bubble array based on shooter.mX value
                        for (int J = 0; J < bubbleArray[i].length; J++) {
                            if (shooter.mX > J * screen_x_division && shooter.mX < (J + 1) * screen_x_division) {
                                j = J;
                                shooter.mX = (J + 1) * screen_x_division - radius;
                                break;
                            }
                        }
                        break;
                    }
                }

                bubbleArray[i][j] = shooter;
                boolean check = false;

                //Explosion on initial hit

                //Upper
                if (i != 0 && bubbleArray[i - 1][j] != null && bubbleArray[i][j].mColor == bubbleArray[i - 1][j].mColor) {
                    bubbleArray[i - 1][j].mAlpha -= 51;
                    check = true;
                    Explosion(i - 1, j);
                }
                //Lower
                if (bubbleArray[i + 1][j] != null && bubbleArray[i][j].mColor == bubbleArray[i + 1][j].mColor && bubbleArray[i + 1][j].mAlpha != 0) {
                    bubbleArray[i + 1][j].mAlpha -= 51;
                    check = true;
                    Explosion(i + 1, j);
                }
                //Right
                if (j != (bubbleArray[i].length - 1) && bubbleArray[i][j + 1] != null && bubbleArray[i][j].mColor == bubbleArray[i][j + 1].mColor) {
                    bubbleArray[i][j + 1].mAlpha -= 51;
                    check = true;
                    Explosion(i, j + 1);
                }
                //Left
                if (j != 0 && bubbleArray[i][j - 1] != null && bubbleArray[i][j].mColor == bubbleArray[i][j - 1].mColor) {
                    bubbleArray[i][j - 1].mAlpha -= 51;
                    check = true;
                    Explosion(i, j - 1);
                }
                //If any explosion occurred, the initial hit bubble disappears
                if (check) {
                    bubbleArray[i][j].mAlpha -= 51;
                }

                //Respawn new shooter
                shooter = null;
                color = Colors[rand.nextInt(Colors.length)];
                shooter = new Bubble(this, getWidth() / 2, getHeight() - radius, color, radius);
            }
        }

        //If bubble has alpha of 0, null the spot
        for(i = 0; i < bubbleArray.length; i++) {
            for (j = 0; j < bubbleArray[i].length; j++) {
                if(bubbleArray[i][j] != null && bubbleArray[i][j].mAlpha == 0) {
                    bubbleArray[i][j] = null;
                }
            }
        }

        //Check for floating bubbles, bubble is removed if there are no bubble, null the space
        for(i = 0; i < bubbleArray.length; i++) {
            for (j = 0; j < bubbleArray[i].length; j++) {
                if(i > 0 && bubbleArray[i][j] != null) {
                    //Bubbles in the middle
                    if(j>0 && j<bubbleArray[i].length-1) {
                        //Remove floating bubble
                        if (bubbleArray[i - 1][j] == null && (bubbleArray[i][j - 1] == null || bubbleArray[i][j + 1] == null) && bubbleArray[i-1][j - 1] == null && bubbleArray[i-1][j + 1] == null) {
                            bubbleArray[i][j] = null;
                        }
                    }
                    //Bubbles along left edge
                    else if(j==0) {
                        //Remove floating bubble
                        if (bubbleArray[i - 1][j] == null && bubbleArray[i][j + 1] == null && bubbleArray[i-1][j + 1] == null) {
                            bubbleArray[i][j] = null;
                        }
                    }
                    //Bubbles along right edge
                    else if(j==bubbleArray[i].length-1) {
                        //Remove floating bubble
                        if (bubbleArray[i - 1][j] == null && bubbleArray[i][j - 1] == null && bubbleArray[i-1][j - 1] == null) {
                            bubbleArray[i][j] = null;
                        }
                    }
                }
            }
        }
        //Fade bubble out
        for(i = 0; i < bubbleArray.length; i++) {
            for (j = 0; j < bubbleArray[i].length; j++) {
                if(bubbleArray[i][j] != null && bubbleArray[i][j].mAlpha > 0 && bubbleArray[i][j].mAlpha < 255) {
                    bubbleArray[i][j].mAlpha -= 51;
                }
            }
        }
        //Check Game's Condition
        boolean restart = false;
        //Win
        for(i = 0; i < bubbleArray.length; i++) {
            for (j = 0; j < bubbleArray[i].length; j++) {
                if(bubbleArray[i][j] != null){
                    restart = false;
                    i = bubbleArray.length;
                    break;
                }
                else{
                    restart = true;
                }
            }
        }
        //Lose
        for(i = 0; i < bubbleArray.length; i++) {
            for (j = 0; j < bubbleArray[i].length; j++) {
                if(bubbleArray[i][j] != null) {
                    if (bubbleArray[i][j].mY > (getHeight() - 2 * getWidth()/10)) {
                        restart = true;
                        i = bubbleArray.length;
                        break;
                    }
                }
            }
        }
        //Reset the Game
        if(restart){
            int x = getWidth()/20, y = getWidth()/20;
            //Empty game board
            for(i = 0; i < bubbleArray.length; i++) {
                for (j = 0; j < bubbleArray[i].length; j++) {
                    bubbleArray[i][j] = null;
                }
            }
            //Fill with bubbles
            for(i = 0; i < bubbleArray.length; i++) {
                for (j = 0; j < bubbleArray[i].length; j++) {
                    color = Colors[rand.nextInt(Colors.length)];
                    bubbleArray[i][j] = new Bubble(this, x, y, color, radius);
                    x += getWidth() / 10;
                }
                x =  getWidth()/20;
                y += getWidth() / 10;
                //Exit setup loop once half the screen is filled
                if((i+1)*getWidth() / 10 >= getHeight()/2){
                    break;
                }
            }
        }

        //Draws the game objects
        renderGame ( c ) ;
    }

    private void renderGame ( Canvas c ) {
        // Render the game elements : bubbles ( fixed , moving , exploding )
        // and aiming arrow .

        //Draw Background
        Paint paint = new Paint();
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(Color.WHITE);
        paint.setAntiAlias(true);
        c.drawPaint(paint);

        //Draw aiming arrow
        arrow.draw(c);
        
        //Draw bubble to be shot
        shooter.draw(c);

        //Draw Bubbles in Array
        for(int i = 0; i < bubbleArray.length; i++) {
            for (int j = 0; j < bubbleArray[i].length; j++) {
                if(bubbleArray[i][j] != null) {
                    bubbleArray[i][j].draw(c);
                }
            }
        }
    }

    //Designated bubble disappears with parameters i and j
    void Explosion(int i, int j){
        //Upper
        if (i != 0 && bubbleArray[i - 1][j] != null && bubbleArray[i][j].mColor == bubbleArray[i - 1][j].mColor && bubbleArray[i - 1][j].mAlpha == 255) {
            bubbleArray[i - 1][j].mAlpha -= 51;
            Explosion(i - 1, j);
        }
        //Lower
        if (bubbleArray[i + 1][j] != null && bubbleArray[i][j].mColor == bubbleArray[i + 1][j].mColor && bubbleArray[i + 1][j].mAlpha == 255) {
            bubbleArray[i + 1][j].mAlpha -= 51;
            Explosion(i + 1, j);
        }
        //Right
        if (j != (bubbleArray[i].length - 1) && bubbleArray[i][j + 1] != null && bubbleArray[i][j].mColor == bubbleArray[i][j + 1].mColor && bubbleArray[i][j + 1].mAlpha == 255) {
            bubbleArray[i][j + 1].mAlpha -= 51;
            Explosion(i, j + 1);
        }
        //Left
        if (j != 0 && bubbleArray[i][j - 1] != null && bubbleArray[i][j].mColor == bubbleArray[i][j - 1].mColor && bubbleArray[i][j - 1].mAlpha == 255) {
            bubbleArray[i][j - 1].mAlpha -= 51;
            Explosion(i, j - 1);
        }
    }
}
