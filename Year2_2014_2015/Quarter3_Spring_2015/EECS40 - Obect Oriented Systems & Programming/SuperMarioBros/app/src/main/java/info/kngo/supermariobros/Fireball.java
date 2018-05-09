package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Jack on 5/13/2015.
 */
public class Fireball {
    //Object Properties
    private MarioSurfaceView view;

    //Rect Boundary
    public Rect dst;
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Physics
    public int mVelX;
    public int fireballVelX = 25;

    //Bitmap
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;

    //Constructor
    public Fireball(MarioSurfaceView view, int x1, int y1, int x2, int y2) {
        this.view = view;
        this.mX1 = x1;
        this.mX2 = x2;
        this.mY1 = y1;
        this.mY2 = y2;
        this.bitmap = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.fireball, options);
        if(this.view.mario.facingRight){
            mVelX = fireballVelX;
        }
        else if(!this.view.mario.facingRight){
            mVelX = -fireballVelX;
        }
    }
    public void tick(Canvas canvas) {

        draw(canvas);

        //Make items scroll
        mX1 += mVelX;
        mX2 += mVelX;
    }
    //Draws Block
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        dst = new Rect (mX1, mY1, mX2, mY2) ; // Where to draw .
        c.drawBitmap(bitmap, null, dst, paint) ;
    }





}
