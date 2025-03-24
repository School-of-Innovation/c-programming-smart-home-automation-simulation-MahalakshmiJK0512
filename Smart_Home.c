#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

// Function prototypes
void initializeSystem(int rooms,int Room_lights[],int Room_temp[],int motion[],int locks[]);
void displayMenu();
void controlLights(int rooms,int Room_lights[]);
void readTemperature(int rooms,int Room_temp[]);
void detectMotion(int rooms,int motion[]);
void securitySystem(int rooms,int locks[]);
void analyzeHouseStatus(int rooms,int Room_lights[],int Room_temp[],int motion[],int locks[]);

int main() {
    int rooms;
    printf("Enter the number of rooms(max %d):",MAX_ROOMS);
    scanf("%d",&rooms);
    if (rooms > MAX_ROOMS || rooms <=0)
    {
        printf("Invalid number of rooms \n");
        return 1;
    }

 int Room_lights[rooms],Room_temp[rooms],motion[rooms],locks[rooms];
 initializeSystem(rooms,Room_lights,Room_temp,motion,locks);

 int choice;
 do
 {
    displayMenu();
    printf("Enter your choice :");
    scanf("%d",&choice);

    switch (choice) {
        case 1:controlLights(rooms,Room_lights);
        break;
        case 2:readTemperature(rooms,Room_temp);
        break;
        case 3:detectMotion(rooms,motion);
        break;
        case 4:securitySystem(rooms,locks);
        break;
        case 5:analyzeHouseStatus(rooms,Room_lights,Room_temp,motion,locks);
        break;
        case 6:printf("Exiting\n");
        break;
        default:printf("Invalid Choice! \n");
    }
 }
 while (choice!=6);
 return 0;
}


void initializeSystem(int rooms,int Room_lights[],int Room_temp[],int motion[],int locks[]) {
    for (int i=0;i<rooms;i++){
        Room_lights[i]=0;
        Room_temp[i]=22;
        motion[i]=0;
        locks[i]=1;
    }
    printf("System Initialized Successfully...\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
   
}
void controlLights(int rooms,int Room_lights[]) {
    int room;
    printf("Enter the room number (1-%d):",rooms);
    scanf("%d",&room);
    if (room <1 || room>rooms ){
        printf("Invalid room number!\n");
        return;
    }
    Room_lights[room-1]=!Room_lights[room-1];
    printf("Light in Room %d is now %s.\n ",room,Room_lights[room-1] ? "ON" : "OFF");
}

void readTemperature(int rooms,int Room_temp[]) {
    int room;
    printf("Enter room number to check the temperature (1-%d:)",rooms);
    scanf("%d",&room);
    if(room<1 || room>rooms){
        printf("Invalid room number!\n");
        return;
    }
    printf("Temperature in Room %d : %d %c\n" ,room,Room_temp[room-1],176);

}
void detectMotion(int rooms,int motion[]) {
    int room;
    printf("Enter the room number to check motion sensor (1-%d):",rooms);
    scanf("%d",&room);
    if(room<1 || room>rooms){
        printf("Invalid room number!\n");
        return;
    }
    printf("Motion in Room %d : %s\n",room,motion[room-1] ? "Motion Detected" : "No Motion");
}

void securitySystem(int rooms,int locks[])
{
    int room;
    printf("Enter room number to lock/unlock (1-%d): ",rooms);
    scanf("%d",&room);
    if(room<1 || room>rooms){
        printf("Invalid room number!\n");
        return;
    }
locks[room-1]=!locks[room-1];
printf("Room %d is now %s.\n",room,locks[room-1] ? "Locked" : "Unlocked");
}


void analyzeHouseStatus(int rooms,int Room_lights[],int Room_temp[],int motion[],int locks[]) {
    printf("\nHouse Status:\n");
    for (int i=0;i<rooms;i++){
        printf("Room %d : Light %s,Temp%d %c ,%s,%s\n",176);
        i+1,
        Room_lights[i] ? "ON" : "OFF",
        Room_temp[i],
        motion[i] ? "Motion Detected" : "No Motion",
        locks[i] ? "Locked" : "Unlocked";
    }
}
