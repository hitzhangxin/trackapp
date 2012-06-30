package a.a.a;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;

public class TrackActivity extends Activity implements OnClickListener {
	/** Called when the activity is first created. */

	global con;
	public int[][][][] suoyin = new int[10][10][10][30];
	public int[][][] count = new int[10][10][10];
	// int [] temp = new int[10];
	int x = 0;
	int y = 0;
	int z = 0;
	int xx = 0;
	int yy = 0;
	int zz = 0;
	int turn = 0;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		con = (global) getApplicationContext();
		con.a = this;

		View mybutton1 = this.findViewById(R.id.button1);
		mybutton1.setOnClickListener(this);
		View mybutton2 = this.findViewById(R.id.button2);
		mybutton2.setOnClickListener(this);
		View mybutton3 = this.findViewById(R.id.button3);
		mybutton3.setOnClickListener(this);
		View mybutton4 = this.findViewById(R.id.button4);
		mybutton4.setOnClickListener(this);

		// count[0][0][0] = 345;
	}

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		switch (v.getId()) {
		case R.id.button2:
			finish();
			break;
		case R.id.button1:
			final EditText text1 = new EditText(this);
			AlertDialog mydialog = new AlertDialog.Builder(this)
					.setView(text1)
					.setPositiveButton("确定",
							new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface dialog,
										int which) {
									// TODO Auto-generated method stub
									if (turn == 0) {
										x = Integer.valueOf(text1.getText()
												.toString());
									} else if (turn == 1) {
										y = Integer.valueOf(text1.getText()
												.toString());
									} else if (turn == 2) {
										z = Integer.valueOf(text1.getText()
												.toString());
										xx = x / 100;
										yy = y / 100;
										zz = z / 100;
										if (count[xx][yy][zz] < 10) {
											suoyin[xx][yy][zz][count[xx][yy][zz] * 3] = x;
											suoyin[xx][yy][zz][count[xx][yy][zz] * 3 + 1] = y;
											suoyin[xx][yy][zz][count[xx][yy][zz] * 3 + 2] = z;
											count[xx][yy][zz]++;
										}
									}
									turn++;
									if (turn == 3) {
										turn = 0;
									}
								}
							}).setNegativeButton("取消", null).show();
			break;
		case R.id.button3:
			final EditText text2 = new EditText(this);
			AlertDialog mydialog2 = new AlertDialog.Builder(this)
					.setView(text2)
					.setPositiveButton("x",
							new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface dialog,
										int which) {
									// TODO Auto-generated method stub
									x = Integer.valueOf(text2.getText()
											.toString());
									Intent intent = new Intent();
									intent.setClass(TrackActivity.this,
											anotherx.class);
									startActivity(intent);
								}
							})
					.setNeutralButton("y",
							new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface dialog,
										int which) {
									y = Integer.valueOf(text2.getText()
											.toString());
									Intent intent = new Intent();
									intent.setClass(TrackActivity.this,
											anothery.class);
									startActivity(intent);
								}
							})
					.setNegativeButton("z",
							new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface dialog,
										int which) {
									z = Integer.valueOf(text2.getText()
											.toString());
									Intent intent = new Intent();
									intent.setClass(TrackActivity.this,
											anotherz.class);
									startActivity(intent);
								}
							}).show();
			break;
		case R.id.button4:
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {
						count[i][j][k] = 0;
						for (int m = 0; m < 30; m++) {
							suoyin[i][j][k][m] = 0;
						}
					}
				}
			}
			AlertDialog mydialog1 = new AlertDialog.Builder(this)
					.setTitle("success").setNegativeButton("确定", null).show();
			break;
		}
	}

}