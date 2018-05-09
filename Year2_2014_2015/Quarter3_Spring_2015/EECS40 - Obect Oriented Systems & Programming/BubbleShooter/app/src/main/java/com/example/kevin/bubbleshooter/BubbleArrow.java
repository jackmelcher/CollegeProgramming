package com.example.kevin.bubbleshooter;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

/**
 * Created by Kevin on 4/8/2015.
 */
public class BubbleArrow {
    private final BubbleShooterView bsv;
    int x1;
    int y1;
    int x2;
    int y2;

    public BubbleArrow(BubbleShooterView bsv, int radius){
        this.bsv = bsv;
        this.x1 = bsv.getWidth()/2;
        this.y1 = bsv.getHeight() - radius;
    }

    public void draw(Canvas c){
        int color = Color.RED;
        Paint paint = new Paint(

        );
        paint.setColor(color) ;
        c.drawLine(this.x1, this.y1, this.x2, this.y2, paint);
    }
}
