package info.kngo.dash_till_puff;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

import java.util.Random;

/**
 * Created by Kevin on 4/22/2015.
 */
public class CosmicObject {
    DashTillPuffSurfaceView view;
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;

    //Velocity
    private int mVelX = -20;

    //Rect Boundary
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    public CosmicObject(DashTillPuffSurfaceView view, int x1, int y1, int x2, int y2,int random){
        this.view = view;
        Bitmap[] bitmaps = {
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffblackhole, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffblueplanet, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffcloud, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffearth, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffglossyplanet, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffgoldenstar, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffneutronstar, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffshinystar, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffstar1, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffstar2, options),
        };
        bitmap = bitmaps[random];
        this.mX1 = x1;
        this.mX2 = x2;
        this.mY1 = y1;
        this.mY2 = y2;
    }
    public void draw(Canvas c){

        Paint paint = new Paint();
        paint.setAntiAlias(true);
        Rect dst = new Rect (mX1-(mX2-mX1)/2, mY1-(mY2-mY1)/2, mX2+(mX2-mX1)-(mX2-mX1)/2, mY2+(mY2-mY1)-(mY2-mY1)/2) ; // Where to draw .
        c.drawBitmap(bitmap, null, dst, paint) ;

        mX1 += mVelX;
        mX2 += mVelX;

    }

}
