package info.kngo.dash_till_puff;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Jack on 4/20/2015.
 */
public class SpaceShip implements TimeConscious {
    // Class properties
    private int ALPHA = 255;

    //Object Properties
    private DashTillPuffSurfaceView view;

    //Rect Boundary
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Paint related
    public int mAlpha;

    //Physics
    public double mAcceleration;
    public double mVelY;

    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;

    //Constructor
    public SpaceShip(DashTillPuffSurfaceView view, int x1, int y1, int x2, int y2){
        this.view = view;
        this.mX1 = x1;
        this.mX2 = x2;
        this.mY1 = y1;
        this.mY2 = y2;
        this.mAlpha = ALPHA;
        bitmap = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffspaceship, options) ;
    }

    public int getX1(){return mX1;}
    public int getX2(){return mX2;}
    public int getY1(){return mY1;}
    public int getY2(){return mY2;}

    @Override
    public void tick(Canvas canvas) {
           draw(canvas);
    }

    //Draws SpaceShip
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setAlpha(mAlpha) ; // Needed for animating disappearance .
        paint.setAntiAlias(true);
        Rect dst = new Rect (getX1(), getY1(), getX2(), getY2()) ; // Where to draw .
        c.drawBitmap(bitmap, null, dst, paint) ;
        this.stepCoordinates();
    }

    //physics of the spaceship
    public void stepCoordinates() {
        int maxY = view.getHeight();

        //Adjust velocity based on acceleration
        mVelY += mAcceleration;
        //Limit the thrust
        if(mVelY > 20){
            mVelY = 20;
        }
        //Limit the falling speed
        if(mVelY < -20){
            mVelY = - 20;
        }
        //Move ship based on the velocity
        mY1 = mY1 + (int)mVelY;
        mY2 = mY2 + (int)mVelY;

        if(mY2 > view.getHeight()){
            mY1 = maxY - 128;
            mY2 = maxY;
            mVelY = 0;
        }
        if(mY1 < 0){
            mY1 = 0;
            mY2 = 128;
            mVelY = 0;
        }
    }
}
