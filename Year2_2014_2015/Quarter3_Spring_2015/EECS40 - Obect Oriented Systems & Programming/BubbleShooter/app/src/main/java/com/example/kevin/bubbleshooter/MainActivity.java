package com.example.kevin.bubbleshooter;

import android.app.Activity;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

/**+
 * Created by
 *      Kevin Ngo (25092065)
 *      Jack Melcher (67574625)
 *      on 4/3/2015.
 */

public class MainActivity extends /*ActionBar*/Activity {

    @Override
    protected void onCreate ( Bundle savedInstanceState ) {
        super . onCreate ( savedInstanceState ) ;
        // Only instantiate the main view
        setContentView ( new BubbleShooterView ( getBaseContext () ) ) ;
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }
/*
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
*/
}
