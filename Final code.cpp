//my basic text editor app.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int size = 1000;
//declaring all the global variables tobe used in the program
string filename;
string contentFile[size];
string backup[size];//for undoing
string redobackup[size];//for redoing function
int linecount= 0;
int coursorLine= 0;
int cursorCol = 0;
// im declaring all the function declarartions
void open();
void view();
void edit();
void save();
void movecursor();
void undo();
void redo();
 
 void open()//my 1st function definataion
 {
 	cout<<"Open File:";
 	getline(cin, filename);//i used getline to read file line by line.
 	ifstream fish(filename.c_str());//the original statement to open the file.
 	linecount = 0;
 	if(fish.is_open()){
 		linecount= 0;
 		while(getline(fish, contentFile[linecount]) && linecount< size)//combined condition.
 		linecount++;
 		fish.close();
 		cout<<"File loaded.\n";
	 }
	 else{
	 	cout<<"File not loaded. starting new file.\n";
	 }
	 for(int i = 0; i < linecount; i++)// using i instead of ++i, personal preference
	 backup[i] = contentFile[i];
	 
	 coursorLine = cursorCol = 0;
 }
 void view()
 {
 	cout<<"File content:\n";
 	for(int i = 0; i < linecount; i++){
 		if (i == coursorLine) cout<<">>";
 		else cout<<"  ";
 		
 		cout << contentFile[i] << "\n";//displays the files content. might add cursor display here
	 }
	 		cout <<"cursor now at line:"<<coursorLine + 1<<", coloumn "<<cursorCol + 1<<"\n";
 }
 void edit()
 {
 	for(int i = 0; i < linecount; i++)
 	backup[i] = contentFile[i];//just simply adds the info
 	cout<<"Enter lines('end'to stop):\n";
 	string line;//to read the file line by line
 	while(getline(cin, line))
 	{ if( line == "end")break;
 	for(int j = linecount; j > coursorLine ; j--){//this is all for cursor location where file it gona get edited.
 	contentFile[j] = contentFile[j - 1];}
 	contentFile[coursorLine] = line;
 	linecount++;
 	coursorLine++;
	 }
 	
 }
 void save()
 {
 	string name;
    cout << "Save as (leave blank to save to '" << filename << "'): ";
    getline(cin, name);
    if (name.empty()) name = filename;

    ifstream check(name.c_str());//this will check for anyy esisting file. to see if overwriting
    if (name != filename && check) {
        cout << "File exists. Overwrite? (y/n): ";
        char ch;
        cin >> ch;
        cin.ignore();//cleanup input buffer.
        if (ch != 'y' && ch != 'Y') return;
    }

    ofstream water(name.c_str());
    for (int i = 0; i < linecount; i++)
        water << contentFile[i] << "\n";
    water.close();
    filename = name;
    cout << "File saved.\n";
 }
 void movecursor()
 {
 	char c;
 	cout<<"Use w/a/s/d to move, z to quit.\n";
 	while(true){
 		cout<<">";
 		cin>>c;
 		cin.ignore();
		if(c == 'Z' || c == 'z')break;// could use switch as well.
		else if(c == 'w' && coursorLine > 0) coursorLine--;
		else if(c == 's' && coursorLine + 1 < linecount) coursorLine++;
		else if(c == 'a' && cursorCol > 0) cursorCol--;
		else if(c == 'd' && cursorCol <contentFile[coursorLine].size()) cursorCol++;
		else cout <<"Invalid Key huh?.\n";
		
		cout<<"cursor now at line:"<<coursorLine + 1<<", coulumn:"<<cursorCol + 1<<"\n";
		}
 }
 void undo()
 {
 	for (int i = 0; i < size; i++)
 	redobackup[i] = contentFile[i];//just copied redobackup in to original content file.
 	for (int i = 0; i < size; i++)
 	contentFile[i] = backup[i];//just copies content file into backup
 	
 	cout<<"Undo finished.\n";
 }
void redo()
{
	for (int i = 0; i < size; i++)
	contentFile[i] = redobackup[i];
	
	cout<<"Redo done.\n";
}
int main()
{
	int x;
	bool y = true;//This is more easier to use than forming another exit function
	while(y)
	{
		cout<<"Menu of all functions:\n";
		cout<<" 1. Open\n 2. view\n 3. Edit\n 4. Save\n 5. movecursor\n 6. Undo\n 7. Redo\n 8. Exit\n ";
		cout<<"choose option:";
		cin>>x;
		cin.ignore();
		switch(x){//handle all the choices 
			case 1: open(); break;//function calls.
			case 2: view(); break;
			case 3: edit(); break;
			case 4: save(); break;
			case 5: movecursor(); break;
			case 6: undo(); break;
			case 7: redo(); break;
			case 8: y = false; break;//bool is used instead of exit.
			default: cout<<"not correct option.\n";
		}
		
	}
	cout<<"File editor closed.\n";
	return 0;
}