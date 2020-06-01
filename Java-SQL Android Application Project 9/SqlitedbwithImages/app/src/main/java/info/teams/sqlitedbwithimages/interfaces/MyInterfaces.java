package info.teams.sqlitedbwithimages.interfaces;

public class MyInterfaces {
    public interface deleteRecord
    {
        void onDeleteRecord(int id);
    }
    public interface updateRecord
    {
        void onUpdateRecord(int id);
    }
}
