package info.kngo.dash_till_puff;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Jack on 4/21/2015.
 */
public class Background implements TimeConscious {

    //Object Properties
    private DashTillPuffSurfaceView view;

    //Rect Boundary
    private int mX1;
    private int mX2;
    private int mY1;
    private int mY2;

    //Velocity
    private int mVelX = -20;

    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;

    //Constructor
    public Background(DashTillPuffSurfaceView view, int x1, int y1, int x2, int y2){
        this.view = view;
        this.mX1 = x1;
        this.mX2 = x2;
        this.mY1 = y1;
        this.mY2 = y2;

        bitmap = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.dashtillpuffwallpaper, options) ;
    }

    //Draws Background
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        Rect dst = new Rect (mX1, mY1, mX2, mY2) ; // Where to draw .
        c.drawBitmap(bitmap, null, dst, paint) ;
    }

    @Override
    public void tick(Canvas canvas) {

        //make the Background scroll
        int resetX1 = view.getWidth();
        int resetX2 = 2*view.getWidth();

        draw(canvas);

        mX1 += mVelX;
        mX2 += mVelX;

        if(mX2 <= 0){
            mX1 = resetX1;
            mX2 = resetX2;
        }


    }
}
