package info.teams.sqlitedbwithimages.activities;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import java.util.ArrayList;

import info.teams.sqlitedbwithimages.R;
import info.teams.sqlitedbwithimages.adapters.RecordAdapter;
import info.teams.sqlitedbwithimages.adapters.playerDataAdapter;
import info.teams.sqlitedbwithimages.adapters.playerRecordAdapter;
import info.teams.sqlitedbwithimages.helper.DatabaseHandler;
import info.teams.sqlitedbwithimages.models.Team;
import info.teams.sqlitedbwithimages.models.PlayerModel;

public class DisplayPlayersList extends AppCompatActivity {
    RecyclerView playerrv;
    playerRecordAdapter playerDataAdapter;
    LinearLayoutManager linearLayoutManager;
    ArrayList<PlayerModel> arrayList;
    DatabaseHandler db;
    String fid="";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display_players_list);
        playerrv=findViewById(R.id.playerrv);
        db=new DatabaseHandler(getApplicationContext());
        linearLayoutManager=new LinearLayoutManager(getApplicationContext());
        playerDataAdapter=new playerRecordAdapter(arrayList,DisplayPlayersList.this);
        playerrv.setLayoutManager(linearLayoutManager);
        playerrv.setAdapter(playerDataAdapter);
        fid=getIntent().getStringExtra("teamid");
        ShowRecords();
    }
    private void ShowRecords() {
        arrayList = new ArrayList<>(db.getAllPlayers(Integer.parseInt(fid)));
        playerDataAdapter.setdata(arrayList);
    }
}
