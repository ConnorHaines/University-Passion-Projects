
package info.teams.sqlitedbwithimages.activities;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

import info.teams.sqlitedbwithimages.helper.DatabaseHandler;
import info.teams.sqlitedbwithimages.R;
import info.teams.sqlitedbwithimages.adapters.RecordAdapter;
import info.teams.sqlitedbwithimages.interfaces.MyInterfaces;
import info.teams.sqlitedbwithimages.models.Team;

public class MainActivity extends AppCompatActivity {
  RecyclerView teamrecyclerview;
  RecordAdapter recordAdapter;
  LinearLayoutManager linearLayoutManager;
  ArrayList<Team>arrayList;
    private DatabaseHandler db;
    FloatingActionButton add;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_activity);
        teamrecyclerview=findViewById(R.id.teamrecyclerview);
        add=findViewById(R.id.addrecord);
        arrayList=new ArrayList<>();
        db=new DatabaseHandler(this);
        linearLayoutManager=new LinearLayoutManager(getApplicationContext());
        teamrecyclerview.setLayoutManager(linearLayoutManager);
        recordAdapter=new RecordAdapter(arrayList, MainActivity.this);
        teamrecyclerview.setAdapter(recordAdapter);
        recordAdapter.setdata(arrayList);
        recordAdapter.setDeleteRecord(new MyInterfaces.deleteRecord() {
            @Override
            public void onDeleteRecord(int id) {
                db.deleteTeam(id);
                ShowRecords();
                recordAdapter.setdata(arrayList);
                  recreate();
                // recordAdapter.notifyDataSetChanged();
            }
        });
        recordAdapter.setUpdateRecord(new MyInterfaces.updateRecord() {
            @Override
            public void onUpdateRecord(int id) {
                Intent intent=new Intent(MainActivity.this,editActivity.class);
                intent.putExtra("rid",String.valueOf(id));
                startActivityForResult(intent,2);
                ShowRecords();
                recordAdapter.setdata(arrayList);
                 recreate();

            }
        });
        recordAdapter.notifyDataSetChanged();

        ShowRecords();
        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(MainActivity.this, InsertDataActivity.class);
                startActivityForResult(intent,1);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode==1)
        {
            arrayList = new ArrayList<>(db.getAllTeams());

            recordAdapter.setdata(arrayList);

        }
        else if(resultCode==2)
        {
            arrayList = new ArrayList<>(db.getAllTeams());
            recordAdapter.setdata(arrayList);

        }else{
            recreate();
        }
    }
    private void ShowRecords() {

        arrayList = new ArrayList<>(db.getAllTeams());
        recordAdapter.setdata(arrayList);

    }
}
