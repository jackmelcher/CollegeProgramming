package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Jack on 5/11/2015.
 */
public class Background implements TimeConscious {

    //Object Properties
    private MarioSurfaceView view;

    //Rect Boundary
    private int mX1;
    private int mX2;
    private int mY1;
    private int mY2;

    //Velocity
    public int mVelX;

    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;

    //Constructor
    public Background(MarioSurfaceView view, int x1, int y1, int x2, int y2, int type) {
        this.view = view;
        this.mX1 = x1;
        this.mX2 = x2;
        this.mY1 = y1;
        this.mY2 = y2;
        if (type == 0) {
            bitmap = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.wallpaper, options);
        }
        if (type == 1) {
            bitmap = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.wallpaper1, options);
        }
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
