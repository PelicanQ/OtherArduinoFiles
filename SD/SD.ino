#include <SPI.h>
#include <SD.h>
void printDir(File dir, int numTabs = 0);
const int chipSelect = 10;
File vals;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!SD.begin(chipSelect)){
    Serial.println("SD failed or not present");
    while(1);
  }
  
  File root = SD.open("/");
 // printDir(root);
  //clearDir("/");
 // printDir(root);
  root.close();
 
  //Now create a new dir and fill with files
 
  vals = SD.open("test.txt");
  printFile(vals);
  vals.close();
  vals = SD.open("test.txt", FILE_WRITE);
}
unsigned long loopCount = 0;
const int p = 30;
void loop() {
  vals.print("time:");
  vals.print(millis());
  Serial.println(millis());
  vals.print(", loopCount:");
  vals.println(loopCount%p);
  if(loopCount % p == 0){
    vals.flush();
  }
  loopCount++;
  delay(500);
  
}
void printFile(File file){
  while(file.available() > 0){
    Serial.print(char(file.read()));
  }
}
void printDir(File dir, int numTabs){
  dir.rewindDirectory();
  Serial.println();
  while(1){
    File nextFile = dir.openNextFile();
    if(!nextFile)
     break;
    
    if(nextFile.isDirectory()){
      for(int i = 0; i < numTabs; i++)
        Serial.print("   ");
      Serial.print(nextFile.name() );
      Serial.println("/");
      printDir(nextFile, numTabs + 1);
    }
    else {
      for(int i = 0; i < numTabs; i++)
        Serial.print("   ");
      Serial.println(nextFile.name());
    }
    nextFile.close();
  }
}
bool clearDir(char path[]){
  char dirPath[strlen(path) + 2];
  strcpy(dirPath, path);
  if(path[strlen(path)-1] != '/')
    strcat(dirPath, "/");
    
  File dir = SD.open(dirPath);
  if(!dir.isDirectory()){
    return false;
  }
  Serial.print("Gonna clear this dir: ");
  Serial.println(dirPath);
  while(true){
    File entry = dir.openNextFile();
    if(!entry){
      Serial.println("No more files to delete");
      return true;
    }
    if(entry.isDirectory()){
      
      char subDirPath[strlen(dirPath) + strlen(entry.name()) + 1];
      strcpy(subDirPath, dirPath);
      strcat(subDirPath, entry.name());
      Serial.print("Entry is directory, path:");
      Serial.println(subDirPath);
      clearDir(subDirPath);
      SD.rmdir(subDirPath);
      continue;
    }
    
    char filePath[strlen(dirPath) + strlen(entry.name())+ 1];
    strcpy(filePath, dirPath);
    strcat(filePath, entry.name());
    Serial.print("Deleting: ");
    Serial.println(filePath);
    SD.remove(filePath);
    entry.close();
    
  }
}
