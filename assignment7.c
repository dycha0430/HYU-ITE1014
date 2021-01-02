#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

//시간에 대한 구조체
typedef struct _time {
    int     minute;
    int     second;
} Time;

//노래 한 곡에 대한 구조체
typedef struct _song {
    char    title[100];
    char    artist[100];
    Time    length;
} Song;

//노래목록에 대한 구조체
typedef struct _songList{
    Song    *songs;
    int     size;
    int     capacity;
} SongList;

//함수 선언
SongList    dataLoad(void);
int         dataSave(SongList);
void        printMenu(void);
void        printSong(Song*);
void        printSongMenu(void);
Song*       searchSong(SongList, char*, char*);
int         editSong(Song*);
int         deleteSong(SongList*, Song*);
int         addSong(SongList*);
void        printAllSongs(SongList);
int         deleteAll(SongList*);

int main(void){
    //노래목록 변수를 선언하고 dataLoad를 통해 파일에서 목록을 받아온다.
    SongList sl = dataLoad();
    Song* song;
    int menu, songMenu, count = 0;
    char title[100], artist[100], ans;
    printf("----- Mini Music Library -----");
    printf("\n\n...Data load success\n");
    while(1){
        printMenu(); //메뉴를 출력한다.

        //메뉴번호를 입력받는다. scanf 오입력 예외처리해준다.
        while(1) {
            if (scanf("%d", &menu) != 1){
                printf("<ERROR> scanf error\n");
                while(getchar() != '\n');
                continue;
            }
            break;
        }

        if (menu == 1){
            count = 0; //노래가 존재하는지 여부를 판단하기 위한 변수
            printf("Input title: ");
            scanf(" %[^\n]s", title); //띄어쓰기를 포함해 제목을 입력받는다.
            printf("Input artist: ");
            scanf(" %[^\n]s", artist); //띄어쓰기를 포함해 가수를 입력받는다.

            for (int i = 0; i < sl.capacity; i++){
                //제목과 가수가 모두 동일하다면 실행한다.
                if (strcmp(sl.songs[i].title , title) == 0){
                    if (strcmp(sl.songs[i].artist, artist) == 0){
                        song = searchSong(sl, title, artist); //searchSong함수를 호출해 알맞은 노래를 불러오고 리턴값을 song에 저장한다.
                        count = 1; //알맞은 노래가 존재한다면 count =1로 한다.
                        printSongMenu(); //1번메뉴안에 딸려오는 메뉴를 출력한다.
                        //메뉴 번호를 오입력 예외처리하여 입력받는다.
                        while(1) {
                            if (scanf("%d", &songMenu) != 1){
                                printf("<ERROR> scanf error\n");
                                while(getchar() != '\n');
                                continue;
                                }
                            break;
                        }
                        if (songMenu == 1){
                            editSong(song); //노래를 수정한다.
                        }
                        else if (songMenu == 2){
                            deleteSong(&sl, song); //노래를 제거한다.
                        }
                        else if (songMenu == 0){
                            break; //다시 처음메뉴로 돌아간다.
                        }
                        break;
                    }
                }
            }
            if (count == 0) //맞는 노래가 하나도 없다면 메시지를 출력한다.
                printf("No song like that!\n");
        }
        else if (menu == 2){
            addSong(&sl); //노래를 추가한다.
        }
        else if (menu == 3){
            printAllSongs(sl); //모든 노래를 출력한다.
        }
        else if (menu == 4){
            printf("Are you sure? (y or n)\n"); //의사를 한번더 학인한다.
            scanf(" %c", &ans);
            if (ans == 'y'){
                deleteAll(&sl); //모든 노래를 삭제한다.
            }
        }
        else if (menu == 0){
            dataSave(sl); //데이터를 파일에 저장한다.
            //메모리 정리.
            free(sl.songs);
            free(song);
            break; //프로그램을 종료한다.
        }
    }
    return 0;
}

//파일 입출력을 통해 노래목록을 불러오는 함수
SongList dataLoad(void)
{
    SongList sl;
    char time[100][100], minute[50][50], second[50][50];
    char copy[50];
    char c;
    int num, ctr, i = 0;
    FILE * f = NULL;
    //파일을 연다.
    f = fopen("example.txt", "r");
    //파일을 여는데 오류가 났다면 메시지를 출력한다.
    if (f == NULL) {
        printf("Open Error!\n");
        return ;
    }
    //노래 개수를 받아온다.
    fscanf(f, "%d", &num);
    //개행문자를 제거해준다.
    fscanf(f, "\n");
    //capacity와 size를 노래개수로 맞춰준다.
    sl.capacity = num;
    sl.size = num;
    //sl.songs를 노래개수만큼 동적할당 해준다.
    sl.songs = (Song *)malloc(num * sizeof(Song));
    //파일의 끝에 도달할때까지 반복한다.
    while(!feof(f)){
        // 개행문자까지 이어가며 각각의 변수에 파일의 내용을 받아와 저장한다.
        fgets(time[i], 50, f);
        fgets(sl.songs[i].artist, 50, f);
        fgets(sl.songs[i].title, 50, f);
        //개행문자를 제거해준다.
        time[i][strlen(time[i])-1] = '\0';
        sl.songs[i].title[strlen(sl.songs[i].title)-1] = '\0';
        sl.songs[i].artist[strlen(sl.songs[i].artist)-1] = '\0';
        //time[i]를 복사해둔다.
        strcpy(copy, time[i]);
        //time[i]를 띄어쓰기를 기준으로 잘라 minute와 second에 각각 저장해준다.
        strcpy(minute[i], strtok(time[i], " "));
        strcpy(second[i], strtok(copy, " "));
        strcpy(second[i], strtok(NULL, " "));
        //minute[i]와 second[i]를 int형을 바꿔 노래목록에 저장해준다.
        sl.songs[i].length.minute = atoi(minute[i]);
        sl.songs[i].length.second = atoi(second[i]);
        //마지막에 도달하면 개행문자를 제거해준다.
        if (i == num-1){
            fscanf(f, "\n");
        }
        i++; //한번 돌때마다 다음 인덱스로 넘어간다.
    }
    //파일을 닫아준다.
    if (fclose(f) != 0){
        printf("Close Error!\n");
    }
    return sl; //노래목록을 리턴한다.
}

//파일에 데이터를 저장한다.
int dataSave(SongList sl)
{
    //파일을 연다.
    FILE* f = NULL;
    f=fopen("example.txt", "w");
    if (f == NULL) {
        printf("Open Error!\n");
        return -1;
    }
    //노래 개수를 받는다.
    fprintf(f, "%d\n", sl.size);
    //분/초가 모두 0분 0초가 아니라면 노래목록을 받는다.
    for (int i = 0; i < sl.capacity; i++){
        if ((sl.songs[i].length.minute != 0) || (sl.songs[i].length.second != 0)){
        fprintf(f, "%d %d\n", sl.songs[i].length.minute,sl.songs[i].length.second);
        fprintf(f, "%s\n", sl.songs[i].artist);
        fprintf(f, "%s\n", sl.songs[i].title);
        }
    }
    if (fclose(f) != 0){
        printf("Close Error!\n");
    }
    printf("...Data save success");
}

//메뉴목록을 출력한다.
void printMenu(void)
{
    printf("-------------------------------\n");
    printf("1. Search\n");
    printf("2. New song\n");
    printf("3. Print all\n");
    printf("4. Delete all\n");
    printf("0. Exit\n");
    printf("-------------------------------\n");
}

//노래 한곡을 출력한다.
void printSong(Song* song)
{
    printf("\nTitle  : %s\n", song -> title);
    printf("Artist : %s\n", song -> artist);
    printf("Length : %d min %d sec\n", song -> length.minute, song -> length.second);
}

//1번 메뉴에 딸린 메뉴목록을 출력한다.
void printSongMenu(void)
{
    printf("-------------------------------\n");
    printf("1. Edit\n");
    printf("2. Delete\n");
    printf("3. Previous\n");
    printf("-------------------------------\n");
}

//사용자가 입력한 노래와 동일한 노래를 찾아 출력해준다.
Song* searchSong(SongList sl, char* title, char* artist)
{
    Song* song = NULL;
    //모든 노래를 돌아가며 검사하여 제목과 가수가 일치하는 노래가 있으면 그 노래를 출력한다.
    for (int i = 0; i < sl.capacity; i++){
        if (strcmp(sl.songs[i].title , title) == 0){
            if (strcmp(sl.songs[i].artist, artist) == 0){
                song = &(sl.songs[i]);
                printSong(song);
                break;
            }
        }
    }
    return song; //찾은 노래 한곡 포인터를 리턴한다.
}

//노래를 수정한다.
int editSong(Song* song)
{
    char newTitle[100], newArtist[100];
    int min = 60, sec = 0;
    // 노래 제목과 가수를 입력받는다.
    printf("Input new title: ");
    scanf(" %[^\n]s", newTitle);
    printf("input new artist: ");
    scanf(" %[^\n]s", newArtist);

    //노래 길이(분/초)를 입력받는다.
    while(1){
        printf("Input new length\n");
        printf("\t\tminute: ");
        scanf("%d", &min);
        //시간이 0부터 60까지의 범위가 아니라면 다시 입력받는다.
        if(min > 60 || min < 0){
            printf("<ERROR> editSong minute size\n");
            continue;
        }
        printf("\t\tsecond: ");
        scanf("%d", &sec);
        //시간이 0부터 60까지의 범위가 아니라면 다시 입력받는다.
        if(sec >= 60 || sec < 0){
            printf("<ERROR> editSong second size\n");
            continue;
        }
        break;
    }
    //매개변수로 받은 song변수에 노래정보를 바꾸어 저장해준다.
    strcpy (song->title, newTitle);
    strcpy (song->artist, newArtist);
    song->length.minute = min;
    song->length.second = sec;
    return 0;
}

//노래 한 곡을 삭제한다.
int deleteSong(SongList* sl, Song* song)
{
    //size를 하나 줄인다.
    (sl->size)--;
    //매개변수로 받은 노래와 일치하는 곡이 있다면 분/초를 모두 0으로 바꾼다.
    for (int i = 0; i < sl->capacity; i++){
        if(strcmp(sl->songs[i].title, song->title) == 0){
            sl->songs[i].length.minute = 0;
            sl->songs[i].length.second = 0;
            printf("\n...delete success\n");
            break;
        }
    }
    return 0;
}

//노래 한 곡을 추가한다.
int addSong(SongList* sl)
{
    char newtitle[100], newartist[100];
    int min, sec, ctr = 0;
    (sl->size)++; //음악이 추가되어 size를 하나 늘려준다.
    ++(sl->capacity); //음악이 추가되어 capacity를 하나 늘려준다.
    //sl->songs의 크기를 1만큼 늘려준다.
    sl->songs = (Song *)realloc(sl->songs, (sl->capacity) * sizeof(Song));
    do{
        ctr = 0;
        //노래 제목과 가수를 입력받는다.
        printf("Input title: ");
        scanf(" %[^\n]s", newtitle);
        printf("Input artist: ");
        scanf(" %[^\n]s", newartist);
        //입력받은 노래와 일치하는 노래가 있다면 오류메시지를 출력한다.
        for (int i = 0; i < (sl->capacity); i++){
            if(strcmp(sl->songs[i].title, newtitle) == 0){
                if(strcmp((sl->songs[i]).artist, newartist) == 0){
                    ctr = 1;
                    printf("<ERROR> Already present\n");
                    break;
                }
            }
        }
    }while(ctr == 1); //일치하는 노래가 있는 경우 계속 반복한다.

    //분, 초가 60초를 넘거나 음수가 입력되지 않도록 입력받는다.
    while(1){
        printf("Input new length\n");
        printf("\t\tminute: ");
        scanf("%d", &min);
        if(min > 60 || min < 0){
            printf("<ERROR> editSong minute size\n");
            continue;
        }
        printf("\t\tsecond: ");
        scanf("%d", &sec);
        if(sec > 60 || sec < 0){
            printf("<ERROR> editSong second size\n");
            continue;
        }
        break;
    }
    //sl->songs의 늘어난 공간에 위의 노래정보를 넣어준다.
    strcpy((sl->songs[(sl->capacity) - 1]).title, newtitle);
    strcpy((sl->songs[(sl->capacity) - 1]).artist, newartist);
    (sl->songs[(sl->capacity) - 1]).length.minute = min;
    (sl->songs[(sl->capacity) - 1]).length.second = sec;
    return 0;
}

//모든 노래를 출력한다.
void printAllSongs(SongList sl)
{
    int ctr = 0; //출력할 노래가 있는지 없는지 확인하는 변수
    //인덱스가 증가하며 모든 노래를 출력한다.
    for(int i = 0; i < (sl.capacity); i++){
        if ((sl.songs[i].length.minute != 0) || (sl.songs[i].length.second != 0)){
            ctr ++;
            printf("%s - %s (%d:%d)\n", sl.songs[i].artist, sl.songs[i].title, sl.songs[i].length.minute, sl.songs[i].length.second);
        }
    }
    //출력할 노래가 하나도 없다면 메시지를 출력한다.
    if (ctr == 0){
        printf("No result\n");
    }
}

//모든 노래를 삭제한다.
int deleteAll(SongList* sl)
{
    //size는 0으로 해준다.
    (sl->size) = 0;
    //돌아가며 모든 노래의 분/초를 0분 0초로 바꿔준다.
    for (int i = 0; i < (sl->capacity); i++){
        (sl->songs[i]).length.minute = 0;
        (sl->songs[i]).length.second = 0;
    }
    printf("...delete success\n");
}
