//17025931
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace coursework
{
    public partial class Form1 : Form
    {
        const int MAXNUMBERS = 30; //declare const int MAXNUMBERS as 30 so it can be used as a global variable
        int searchNumber = 0; //declare searchNumber as a global variable
        int mid = 0; //declare mid as a global variable 
        int tracker = 0; //declare tracker as a global variable

        public Form1()
        {
            InitializeComponent();



        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Update_Stats(); //calls update stats
            pb_Bin.AllowDrop = true; //sets allowdrop for the picture box d&d

        }

        private int DupFun(int integer)
        {
            for (int i = 0; i < lst_Numbers.Items.Count; i++) //loops through the lists item count
            {
                if (integer == int.Parse(lst_Numbers.Items[i].ToString())) //until it finds a duplicate
                {

                    return 1; //if it finds one it returns 1
                }
            }

            return 0; //if it doesn't it returns 0
        }

        private void bubble_sort()
        {
            int t; //declare int t
            for (int p = 0; p <= lst_Numbers.Items.Count - 2; p++) //while p is less than or equal to the count of the list(minus2) it will loop
            {
                for (int i = 0; i <= lst_Numbers.Items.Count - 2; i++) //loops through the lists item count
                {
                    if (int.Parse(lst_Numbers.Items[i].ToString()) > int.Parse(lst_Numbers.Items[i + 1].ToString())) //if i is greater than i+1
                    {
                        t = int.Parse(lst_Numbers.Items[i + 1].ToString()); //change the value of t
                        lst_Numbers.Items[i + 1] = lst_Numbers.Items[i]; //make item[i] equal to item[i + 1]
                        lst_Numbers.Items[i] = t; //makes item[i] equal to t
                    }
                }
            }
        }

        private void btn_Exit_Click(object sender, EventArgs e)
        {
            this.Close(); //closes the form
        }

        private void btn_Shuffle_Click(object sender, EventArgs e)
        {
            ListBox.ObjectCollection list = lst_Numbers.Items; //Represents the collection of items in a ListBox.
            Random rng = new Random(); //create new random
            int i = list.Count; //declare i and make it equal to the amount of values in the list
            lst_Numbers.BeginUpdate();  //prevents the control from drawing until end update is called
            while (i > 1) //while the number of values in the list is more than one
            {
                i--; //take one away
                int n = rng.Next(i + 1); //create n and make it equal to the next random (i + 1)
                object value = list[n]; //makes value equal to list[n]
                list[n] = list[i]; //makes list[n] equal to list [i]
                list[i] = value; //makes list[i] equal to value
            }
            lst_Numbers.EndUpdate(); 
            lst_Numbers.Invalidate();
            Update_Stats(); //calls update stats
        }

        private void btn_Initialise_Click(object sender, EventArgs e)
        {
            lst_Numbers.Items.Clear(); //clears the listbox

            if (rad_Unsort.Checked == true) //if the unsorted radio button is checked
            {
                var rand = new Random();
                //for (int i = 0; i < 30; i++)
                while (lst_Numbers.Items.Count < MAXNUMBERS) //loops until list count is equal to 30 
                {
                    int index = rand.Next(0, 101); //random number between 0 and 101
                    if (DupFun(index) != 1) //if duplicate function returns anything except a 1
                        lst_Numbers.Items.Add(index); //add to the end

                }

            }
            else if (rad_Sort.Checked == true)
            {
                var rand = new Random();
                //for (int i = 0; i < 30; i++)
                while (lst_Numbers.Items.Count < MAXNUMBERS)
                {
                    int index = rand.Next(0, 101);
                    if (DupFun(index) != 1)
                        lst_Numbers.Items.Add(index);
                }
                
                bubble_sort(); //calls bubble sort
            }

            Update_Stats(); //calls update stats

        }

        private int insertSorted()
        {
            for (int i = 0; i < lst_Numbers.Items.Count; i++) //loops through the list count
            {
                if (int.Parse(tb_Insert.Text) < int.Parse(lst_Numbers.Items[i].ToString())) //if the number inserted is less than the number we're looking at
                {
                    lst_Numbers.Items.Insert(i, ""); //insert blank
                    lst_Numbers.Items[i] = int.Parse(tb_Insert.Text); //set value of blank to the number user inserted
                    return 1; //return 1
                }
            }
            return 0; //otherwise return 0
        }

        private void btn_Insert_Click(object sender, EventArgs e)
        {
            int test;//check for int datatype
            if (tb_Insert.Text != "") //check they don't click insert straight away
            {
                if (!string.IsNullOrEmpty(tb_Insert.Text)) //check the string isn't null or empty
                {
                    if (int.TryParse(tb_Insert.Text, out test)) //tries to parse it to an integer
                    {
                        if (DupFun(int.Parse(tb_Insert.Text.ToString())) != 1) //if duplicate function doesn't return 1
                        {
                            if (int.Parse(tb_Insert.Text) >= 0 && int.Parse(tb_Insert.Text) <= 100) //if the number is less than 100 and over 0 (or equal to)
                            {
                                if (rad_Sort.Checked == true) //if the sort radio button is checked
                                {
                                    if (insertSorted() == 0) //and insert sorted returns a 0
                                    {
                                        lst_Numbers.Items.Add(int.Parse(tb_Insert.Text)); //add to the end
                                    }
                                }
                                if (rad_Unsort.Checked == true) //if the unsort radio button is checked
                                {
                                    lst_Numbers.Items.Add(int.Parse(tb_Insert.Text)); //add to the end
                                }
                            }
                            else MessageBox.Show("Please insert values between 0 and 100!");
                        }
                        else MessageBox.Show("This number has already been inserted!");
                    }
                    else MessageBox.Show("Please insert a full integer only!");
                }
                else MessageBox.Show("Please insert a value!");
            }
            else MessageBox.Show("Please insert a value!");

            Update_Stats(); //call update stats
        }

        private void Update_Stats() //this whole thing updates stats
        {
            if (lst_Numbers.Items.Count == 0)
            {

                lbl_NumberEntries.Text = "Number of Entries: 0 ";
                lbl_First.Text = "First Value: ";
                lbl_Last.Text = "Last Value: ";
                lbl_Max.Text = "Maximum: ";
                lbl_Min.Text = "Minimum: ";
                tb_Insert.Text = String.Empty;
                btn_Search.Enabled = false;
                tb_Search.Enabled = false;
                btn_Clear.Enabled = false;
                btn_Delete.Enabled = false;
            }
            else
            {

                lbl_NumberEntries.Text = "Number of Entries: " + lst_Numbers.Items.Count;
                lbl_First.Text = "First Value: " + lst_Numbers.Items[0].ToString();
                lbl_Last.Text = "Last Value: " + lst_Numbers.Items[lst_Numbers.Items.Count - 1].ToString();
                int maxNumber;
                int minNumber;
                maxNumber = int.Parse(lst_Numbers.Items[0].ToString());
                minNumber = int.Parse(lst_Numbers.Items[0].ToString());
                for (int i = 0; i < lst_Numbers.Items.Count; i++)
                {

                    int currentNumber = int.Parse(lst_Numbers.Items[i].ToString());
                    if (currentNumber > maxNumber)
                    {
                        maxNumber = currentNumber;
                    }

                    if (currentNumber < minNumber)
                    {
                        minNumber = currentNumber;
                    }
                }
                lbl_Max.Text = "Maximum: " + maxNumber;
                lbl_Min.Text = "Minimum: " + minNumber;
                tb_Insert.Text = String.Empty;
                tb_Search.Text = String.Empty;
                btn_Search.Enabled = true;
                tb_Search.Enabled = true;
                btn_Clear.Enabled = true;
                btn_Delete.Enabled = true;
            }
            if (rad_Unsort.Checked == true)
            {
                btn_Shuffle.Enabled = true;
                rad_Binary.Enabled = false;
                rad_Linear.Checked = true;
            }
            else if (rad_Sort.Checked == true)
            {
                rad_Binary.Enabled = true;
                btn_Shuffle.Enabled = false;
            }
            if (lst_Numbers.Items.Count == MAXNUMBERS)
            {
                btn_Insert.Enabled = false;
                tb_Insert.Enabled = false;
                btn_Initialise.Enabled = false;
            }
            else
            {
                btn_Insert.Enabled = true;
                tb_Insert.Enabled = true;
                btn_Initialise.Enabled = true;
            }
            
            if (lst_Numbers.Items.Count >= 2)
            {
                btn_Shuffle.Enabled = true;
            }
            else
            {
                btn_Shuffle.Enabled = false;
            }

            if (lst_Numbers.Items.Count  > 0 && rad_Sort.Checked == true )
            {
                btn_Shuffle.Enabled = false;
            }
            else if(lst_Numbers.Items.Count < 30 && rad_Sort.Checked == true && lst_Numbers.Items.Count != 0)
            {
                btn_Shuffle.Enabled = true;
            }

        }

        private int linSearch()
        {

            searchNumber = int.Parse(tb_Search.Text); //make a new variable with the value of whatever the user searched for 
            int Found = 0; //make a new int with the starting value of 0
            for (int i = 0; i < lst_Numbers.Items.Count; i++) //loop through the list
            {
                if (lst_Numbers.Items[i].ToString() == searchNumber.ToString()) //if the number found matches the number that the user searched for
                {
                    lst_Numbers.SetSelected(i, true); //set the number to selected
                    Found = 1; //set found to 1 

                    return i; //return i
                }
            }
            if (Found == 0) //if it is not found 

            {
                return -1; //it will return -1
            }


            return 0; //otherwise will return 0

        }

        private int binSearch()
        {
            
            int min = 0; //make variable min equal to 0
            int max = lst_Numbers.Items.Count - 1;  //make variable max equal to the number of items in the list - 1
            while (min <= max) //loop while min is less than or equal to max
            {
                mid = (min + max) / 2; //change the value of mid to equal min + max divided by two
                tracker++; //add 1 to the tracker variable

                if (int.Parse(tb_Search.Text) == int.Parse(lst_Numbers.Items[mid].ToString())) //if the number the user searched for equals the number found
                {
                    return mid; //return mid
                }
                else if (int.Parse(tb_Search.Text) < int.Parse(lst_Numbers.Items[mid].ToString())) //if the number the user searched for is less than the number found
                {
                    max = mid - 1; //changes the max to mid - 1
                }
                else //otherwise
                {
                    min = mid + 1; //change min to mid + 1
                }
            }
            return -1; //returns -1
        }

        private void btn_Search_Click(object sender, EventArgs e)
        {
            int test;//check for int datatype
            if (tb_Search.Text != "") //checks that they didn't click search immediately
            {
                if (!string.IsNullOrEmpty(tb_Search.Text)) //checks its not null or empty
                {
                    if (int.TryParse(tb_Search.Text, out test)) //tries to parse it as an int

                    {
                        if (int.Parse(tb_Search.Text) >= 0 && int.Parse(tb_Search.Text) <= 100) //checks the searchnumber is between 1 and 100 or equal to
                        {
                            if (rad_Linear.Checked == true) //if the linear button is checked
                            {
                                if (linSearch() == -1) //if the linear search returned -1
                                {
                                    MessageBox.Show("Sorry! We could not find your number! Please either try again or search for a different number.");
                                }
                                else //otherwise..
                                {
                                    MessageBox.Show(searchNumber + " is in the list as position " + (linSearch() + 1) + ". Found with Linear Search.");
                                    MessageBox.Show(" We did " + (linSearch() + 1) + " comparisons.");
                                }
                            }

                            if (rad_Binary.Checked == true) //if the binary button is checked
                            {
                                if (binSearch() == -1) //if the binary search returned -1
                                {
                                    MessageBox.Show("Sorry! We could not find your number! Please either try again or search for a different number.");
                                }
                                else //otherwise..
                                {
                                    lst_Numbers.SetSelected(mid, true); //selects the number and highlights it
                                    MessageBox.Show(tb_Search.Text + " is in the list at position " + (mid+1) + ". Found with Binary Search"); 
                                    MessageBox.Show(" We did " + tracker + " comparisons.");
                                }
                            }
                        }
                        else MessageBox.Show("Please insert values between 0 and 100!");
                    }
                    else MessageBox.Show("Please insert a full integer only!");
                }
                else MessageBox.Show("Please insert a value!");
            }
            else MessageBox.Show("Please insert a value!");
            Update_Stats();
        }

        private void btn_Clear_Click(object sender, EventArgs e)
        {

            lst_Numbers.Items.Clear(); //clears the list
            Update_Stats(); //calls update stats
        }


        private void Delete()
        {
            ListBox.SelectedObjectCollection selectedItems = new ListBox.SelectedObjectCollection(lst_Numbers); //sets selecteditems to a new selected object using lst_numbers
            selectedItems = lst_Numbers.SelectedItems; //makes selecteditems equal to the list number selected items

            if (lst_Numbers.SelectedIndex != -1) //if the selected index does not equal -1
            {
                for (int i = selectedItems.Count - 1; i >= 0; i--) //loops until there is nothing left in the list
                    lst_Numbers.Items.Remove(selectedItems[i]); //removes selected item
            }
            else
                MessageBox.Show("Select a number to delete! ");
        }

        private void btn_Delete_Click(object sender, EventArgs e)
        {
            Delete(); //deletes whatever is selecter
            Update_Stats(); //calls update stats
        }

        private void btn_Sort_CheckedChanged(object sender, EventArgs e)
        {
            
            bubble_sort();  //if the sort buttons check changes it will call bubblesort..
            Update_Stats();//..update stats..
            rad_Binary.Enabled = true ;//..and will enable the binary button..
            btn_Shuffle.Enabled = false;//..and disable the shuffle button
            
        }

        private void pb_Bin_DragDrop(object sender, DragEventArgs e)
        {
            Delete(); //deletes whatever number was dropped on top of it 
            Update_Stats(); // calls update stats
        }

        private void lst_Numbers_MouseDown_1(object sender, MouseEventArgs e)
        {
            lst_Numbers.DoDragDrop(lst_Numbers.SelectedIndex, DragDropEffects.Move); //starts the drag drop when you start dragging a number
        }

        private void pb_Bin_DragEnter_1(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Move; //moves the number
        }

        private void btn_Unsort_CheckedChanged(object sender, EventArgs e)
        {
            Update_Stats(); //if the unsort buttons check changes it will call update stats
        }
    }
} //430 lines of pure blood, sweat and tears.