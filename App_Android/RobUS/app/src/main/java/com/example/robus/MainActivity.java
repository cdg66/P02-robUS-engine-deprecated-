package com.example.robus;

import android.graphics.Color;
import android.graphics.drawable.DrawableContainer;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import com.google.android.material.bottomnavigation.BottomNavigationView;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.example.robus.databinding.ActivityMainBinding;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {


    private ImageView flag1;
    private ImageView flag2;
    private ImageView flag3;
    private ImageView flag4;
    private ImageView flag5;
    private ArrayList<Boolean> isFlag;
    private ArrayList<ImageView> flags;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.main);

        flag1 = findViewById(R.id.flag1);
        flag2 = findViewById(R.id.flag2);
        flag3 = findViewById(R.id.flag3);
        flag4 = findViewById(R.id.flag4);
        flag5 = findViewById(R.id.flag5);

        flags = new ArrayList<ImageView>();
        flags.add(flag1);
        flags.add(flag2);
        flags.add(flag3);
        flags.add(flag4);
        flags.add(flag5);

       isFlag = new ArrayList<Boolean>();
       for(int i = 0; i<5;i++)
       {
           isFlag.add(true);
       }



    }




    public void placerDrapeau(View view)
    {
        boolean isFini = false;
        for(int i = 4; i>=0 && !isFini;i--)
        {
            if(isFlag.get(i) == true)
            {
                flags.get(i).setImageDrawable(getResources().getDrawable(R.drawable.ic_baseline_flag_24));
                isFlag.set(i, false);
                isFini = true;

            }
            if(i == 0)
            {
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setTitle("Il n'y a plus de drapeau");
                builder.create().show();
            }
        }


    }

}