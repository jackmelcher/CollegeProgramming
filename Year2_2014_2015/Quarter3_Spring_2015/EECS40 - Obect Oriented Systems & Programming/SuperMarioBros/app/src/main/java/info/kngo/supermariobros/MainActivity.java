package info.kngo.supermariobros;

import android.app.Activity;
import android.os.CountDownTimer;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {
    static int test = 0;
    @Override
    protected void onCreate ( Bundle savedInstanceState ) {
        super . onCreate ( savedInstanceState ) ;
        setContentView(new MarioSurfaceView(getBaseContext())) ;

    }
}