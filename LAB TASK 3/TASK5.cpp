#include <iostream>
#include <string>
using namespace std;
class MusicPlayer{
string playlist[100];
int songCount;
string currentlyPlayingSong;
public:
MusicPlayer(){
songCount=0;
}
void add(string song){
if(songCount<100){
playlist[songCount]=song;
cout<<"song added: "<<song<<" to playlist"<<endl;
songCount++;
}
else{
cout<<"play list is full."<<endl;
}
}
void removeSong(string song){
int i,index=-1;
for(i=0;i<songCount;i++){
if(playlist[i]==song){
index=i;
break;
}
}
if (index!=-1){
for(i=index;i<songCount-1;i++){
playlist[i]=playlist[i+1];
}
songCount--;

cout << "Removed song: " << song << endl;
}
else {
cout << "Song not found in the playlist." << endl;
}
}
void playSong(string song){
int i,c=0;
for (int i = 0; i < songCount; i++) {
if (playlist[i] == song) {
currentlyPlayingSong = song;
c=1;
break;}}
if(c==1){
cout << "Now playing: " << song << endl;
}
else {
cout << "Song not found in the playlist." << endl;
}
}
void display(){
int i;
if(songCount==0){
cout<<"play list is empty\n";

}
else{
cout<<"\n..................PLAY LIST .............................\n";
for (int i = 0; i < songCount; i++) {

cout << "- " << playlist[i] << endl;
}
cout<<"................................................\n\n";
}
}
};

int main(){
MusicPlayer player;
player.add("song A");
player.add("song B");
player.add("song C");
player.display();
player.playSong("song A");
player.removeSong("song C");
player.display();
return 0;
}
