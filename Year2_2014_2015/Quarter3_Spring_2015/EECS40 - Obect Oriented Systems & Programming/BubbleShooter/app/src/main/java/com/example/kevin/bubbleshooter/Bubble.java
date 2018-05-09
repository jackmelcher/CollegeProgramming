package com.example.kevin.bubbleshooter;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

/**+
 * Created by
 *      Kevin Ngo (25092065)
 *      Jack Melcher (67574625)
 *      on 4/3/2015.
 */
public class Bubble {
    // Class properties
    private int ALPHA = 255;

    //Object Properties
    private final BubbleShooterView bsv;
    //position
    public        float              mX;
    public        float              mY;
    //Circle
    private final int mR;
    public final int mColor;
    public int mAlpha;
    //Velocity
    public       double              mVelX;
    public       double              mVelY;

    //Constructor
    public Bubble(BubbleShooterView bsv, int x, int y, int color, int radius){
        this.bsv = bsv;
        this.mR = radius;
        this.mX     = x;
        this.mY     = y;
        this.mColor = color;
        this.mAlpha = ALPHA;
    }

    public float getX() { return mX; }
    public float getY() { return mY; }
    public int getR() { return mR; }

    //Draws a circle
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setColor(mColor) ;
        paint.setAlpha(mAlpha) ; // Needed for animating disappearance .
        paint.setAntiAlias(true);
        c.drawCircle ( this.getX(), this.getY(), this.getR(), paint ) ;
        this.stepCoordinates();
    }

    //physics of the ball.
    public void stepCoordinates(){
        int maxX = bsv.getWidth();
        int maxY = bsv.getHeight();

        if(mVelX != 0 || mVelX !=0) {
            mX += mVelX;
            mY += mVelY;

            if (mX > (maxX - mR)) {
                mVelX = -mVelX;
                mX = maxX - mR;
            } else if (mX < mR) {
                mVelX = -mVelX;
                mX = mR;
            }
            if (mY > (maxY - mR)) {
                mVelY = -mVelY;
                mY = maxY - mR;
            } else if (mY < mR) {
                mVelY = -mVelY;
                mY = mR;
            }
        }
    }
}
