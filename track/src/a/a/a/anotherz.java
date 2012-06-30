package a.a.a;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class anotherz extends Activity {

	global con;
	int[] temp;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.a);

		ListView list = (ListView) findViewById(R.id.listView1);

		ArrayList<String> li = new ArrayList<String>();
		String tm = new String();
		con = (global) getApplicationContext();
		int i = 0;
		int j = 0;
		int k = 0;
		int zzz;
		zzz = con.a.z;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				if (con.a.count[i][j][zzz] != 0) {
					for (k = 0; k < con.a.count[i][j][zzz]; k++) {
						//System.out.println("x="+con.a.suoyin[xxx][i][j][k * 3]);
						//System.out.println("y="+con.a.suoyin[xxx][i][j][k * 3+1]);
						//System.out.println("z="+con.a.suoyin[xxx][i][j][k * 3+2]);
						tm = "";
						tm = "x: "
								+ Integer
										.toString(con.a.suoyin[i][j][zzz][k * 3])
								+ "y: "
								+ Integer
										.toString(con.a.suoyin[i][j][zzz][k * 3 + 1])
								+ "z: "
								+ Integer
										.toString(con.a.suoyin[i][j][zzz][k * 3 + 2]);
						li.add(tm);
						System.out.println("tm" + tm);
					}
				}
			}
		}
		// li.add("num1");
		// li.add("num2");
		list.setAdapter(new ArrayAdapter<String>(this,
				android.R.layout.simple_expandable_list_item_1, li));

	}

}
