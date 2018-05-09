package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Jack on 5/15/2015.
 */
public class Flag implements TimeConscious{
    //Object Properties
    private MarioSurfaceView view;

    public double mVelX;

    //Rect Boundary
    public Rect dst;
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Bitmaps
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmaps[];

    //Booleans
    boolean finish;

    //Constructor
    public Flag(MarioSurfaceView view, int x1, int y1, int x2, int y2) {
        this.view = view;
        this.mX1 = x1;
        this.mX2 = x2;
        this.mY1 = y1;
        this.mY2 = y2;

        Bitmap[] bitmaps = {
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.flag1, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.flag2, options),
        };
        this.bitmaps = bitmaps;
    }

    @Override
    public void tick(Canvas canvas) {

        //Make items scroll
        mX1 += mVelX;
        mX2 += mVelX;

        Paint paint = new Paint();
        paint.setAntiAlias(true);
        dst = new Rect (mX1, mY1, mX2, mY2) ; // Where to draw .
        if(!finish) {
            canvas.drawBitmap(bitmaps[0], null, dst, paint);
        }
        else{canvas.drawBitmap(bitmaps[1], null, dst, paint);}
    }
}
