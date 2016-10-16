package com.example.root.dynamiclibtest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void getAndShowIp(View i){
        TextView tv = (TextView) findViewById(R.id.textView);
        tv.setText(GetMyIpSuperFormatted());
    }

    //core lib
    public static native String GetMyIP();

    //lib a
    static {
        System.loadLibrary("core");
        System.loadLibrary("a");
        System.loadLibrary("b");
    }

    //a lib
    public static native String GetMyIpFormatted();

    //b lib
    public static native String GetMyIpSuperFormatted();
}
