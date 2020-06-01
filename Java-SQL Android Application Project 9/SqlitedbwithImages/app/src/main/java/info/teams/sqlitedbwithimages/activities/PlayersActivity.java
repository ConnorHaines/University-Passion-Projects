package info.teams.sqlitedbwithimages.activities;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import info.teams.sqlitedbwithimages.R;
import info.teams.sqlitedbwithimages.helper.DatabaseHandler;
import info.teams.sqlitedbwithimages.models.PlayerModel;

public class PlayersActivity extends AppCompatActivity implements View.OnClickListener {
EditText playername,playerpositon;
Button saveplayer;
String teamid,player,position;
private DatabaseHandler db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new);
        playername=findViewById(R.id.etpname);
        playerpositon=findViewById(R.id.etppos);
        saveplayer=findViewById(R.id.saveplayer);
        db=new DatabaseHandler(getApplicationContext());
        saveplayer.setOnClickListener(this);
        teamid=getIntent().getStringExtra("teamid");
        getValues();
    }
    private void getValues(){
        player = playername.getText().toString();
        position=playerpositon.getText().toString();

    }
    @Override
    public void onClick(View view) {
        boolean error=false;
        player=playername.getText().toString();
        position=playerpositon.getText().toString();
        if(player.equals(""))
        {
            Toast.makeText(this, "player name must be selected", Toast.LENGTH_SHORT).show();
            error=true;
        }
        if(position.equals(""))
        {
            Toast.makeText(this, "player positon should not be empty", Toast.LENGTH_SHORT).show();
            error=true;
        }
        if(error)
            return;
       adPlayer(player,position,teamid);
    }
    private void adPlayer(String player,String position,String teamid){
        getValues();

        db.addPlayers(new PlayerModel(player, position,Integer.parseInt(teamid)));
        Toast.makeText(getApplicationContext(),"Saved player successfully", Toast.LENGTH_LONG).show();
//        Intent intent=new Intent();
//        setResult(RESULT_OK,intent);
            finish();
    }
}
