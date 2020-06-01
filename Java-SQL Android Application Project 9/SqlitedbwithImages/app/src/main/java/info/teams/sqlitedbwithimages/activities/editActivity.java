package info.teams.sqlitedbwithimages.activities;

import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;

import info.teams.sqlitedbwithimages.R;
import info.teams.sqlitedbwithimages.helper.DatabaseHandler;
import info.teams.sqlitedbwithimages.models.Team;

public class editActivity  extends Activity {

    private EditText fname,teasize;
    private ImageView pic;
    private DatabaseHandler db;
    private String f_name,teamsize;
    private ListView lv;
    //    private dataAdapter data;
//    private PlayerModel dataModel;
    private Bitmap bp;
    private byte[] photo;
    String rid;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_insert);

        //Instantiate database handler
        db=new DatabaseHandler(this);


//       lv = (ListView) findViewById(R.id.list1);
        pic= findViewById(R.id.pic);
        fname= findViewById(R.id.txt1);
        teasize=findViewById(R.id.txt2);
        rid=getIntent().getStringExtra("rid");

    }

    public void buttonClicked(View v){
        int id=v.getId();

        switch(id){

            case R.id.save:

                if(fname.getText().toString().trim().equals("")){
                    Toast.makeText(getApplicationContext(),"Name edit text is empty, Enter name", Toast.LENGTH_LONG).show();
                }  else{
                    UpdateTeam(id);
                }

                break;

//            case R.id.display:
//
//                      //  ShowRecords();
//                break;
            case R.id.pic:
                selectImage();
                break;
        }
    }

    public void selectImage(){
        Intent photoPickerIntent = new Intent(Intent.ACTION_PICK);
        photoPickerIntent.setType("image/*");
        startActivityForResult(photoPickerIntent, 2);
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        switch(requestCode) {
            case 2:
                if(resultCode == RESULT_OK){
                    Uri choosenImage = data.getData();

                    if(choosenImage !=null){

                        bp=decodeUri(choosenImage, 400);
                        pic.setImageBitmap(bp);
                    }
                }
        }
    }


    //COnvert and resize our image to 400dp for faster uploading our images to DB
    protected Bitmap decodeUri(Uri selectedImage, int REQUIRED_SIZE) {

        try {

            // Decode image size
            BitmapFactory.Options o = new BitmapFactory.Options();
            o.inJustDecodeBounds = true;
            BitmapFactory.decodeStream(getContentResolver().openInputStream(selectedImage), null, o);

            // The new size we want to scale to
            // final int REQUIRED_SIZE =  size;

            // Find the correct scale value. It should be the power of 2.
            int width_tmp = o.outWidth, height_tmp = o.outHeight;
            int scale = 1;
            while (true) {
                if (width_tmp / 2 < REQUIRED_SIZE
                        || height_tmp / 2 < REQUIRED_SIZE) {
                    break;
                }
                width_tmp /= 2;
                height_tmp /= 2;
                scale *= 2;
            }

            // Decode with inSampleSize
            BitmapFactory.Options o2 = new BitmapFactory.Options();
            o2.inSampleSize = scale;
            return BitmapFactory.decodeStream(getContentResolver().openInputStream(selectedImage), null, o2);
        }
        catch (Exception e){
            e.printStackTrace();
        }
        return null;
    }

    //Convert bitmap to bytes
    @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR1)
    private byte[] profileImage(Bitmap b){

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        b.compress(Bitmap.CompressFormat.PNG, 0, bos);
        return bos.toByteArray();

    }



    // function to get values from the Edittext and image
    private void getValues(){
        f_name = fname.getText().toString();
        photo = profileImage(bp);
        teamsize=teasize.getText().toString();

    }


    @Override
    public void onBackPressed() {
        super.onBackPressed();
        Intent intent=new Intent();
        setResult(RESULT_OK,intent);
        finish();
    }
    //Insert data to the database
    private void UpdateTeam(int id){
        getValues();

        db.updateTeam(new Team(f_name, photo,teamsize),rid);
        Toast.makeText(getApplicationContext(),"updated successfully", Toast.LENGTH_LONG).show();
        Intent intent=new Intent();
        setResult(RESULT_OK,intent);
        finish();
    }
    //Retrieve data from the database and set to the list view
   /* private void ShowRecords(){
        final ArrayList<PlayerModel> teams = new ArrayList<>(db.getAllTeams());
        data=new dataAdapter(this, teams);

        lv.setAdapter(data);

        lv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                dataModel = teams.get(position);

               Toast.makeText(getApplicationContext(),String.valueOf(dataModel.getID()), Toast.LENGTH_SHORT).show();
            }
        });
    }*/
}
