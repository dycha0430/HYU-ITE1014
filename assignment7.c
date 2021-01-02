#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

//�ð��� ���� ����ü
typedef struct _time {
    int     minute;
    int     second;
} Time;

//�뷡 �� � ���� ����ü
typedef struct _song {
    char    title[100];
    char    artist[100];
    Time    length;
} Song;

//�뷡��Ͽ� ���� ����ü
typedef struct _songList{
    Song    *songs;
    int     size;
    int     capacity;
} SongList;

//�Լ� ����
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
    //�뷡��� ������ �����ϰ� dataLoad�� ���� ���Ͽ��� ����� �޾ƿ´�.
    SongList sl = dataLoad();
    Song* song;
    int menu, songMenu, count = 0;
    char title[100], artist[100], ans;
    printf("----- Mini Music Library -----");
    printf("\n\n...Data load success\n");
    while(1){
        printMenu(); //�޴��� ����Ѵ�.

        //�޴���ȣ�� �Է¹޴´�. scanf ���Է� ����ó�����ش�.
        while(1) {
            if (scanf("%d", &menu) != 1){
                printf("<ERROR> scanf error\n");
                while(getchar() != '\n');
                continue;
            }
            break;
        }

        if (menu == 1){
            count = 0; //�뷡�� �����ϴ��� ���θ� �Ǵ��ϱ� ���� ����
            printf("Input title: ");
            scanf(" %[^\n]s", title); //���⸦ ������ ������ �Է¹޴´�.
            printf("Input artist: ");
            scanf(" %[^\n]s", artist); //���⸦ ������ ������ �Է¹޴´�.

            for (int i = 0; i < sl.capacity; i++){
                //����� ������ ��� �����ϴٸ� �����Ѵ�.
                if (strcmp(sl.songs[i].title , title) == 0){
                    if (strcmp(sl.songs[i].artist, artist) == 0){
                        song = searchSong(sl, title, artist); //searchSong�Լ��� ȣ���� �˸��� �뷡�� �ҷ����� ���ϰ��� song�� �����Ѵ�.
                        count = 1; //�˸��� �뷡�� �����Ѵٸ� count =1�� �Ѵ�.
                        printSongMenu(); //1���޴��ȿ� �������� �޴��� ����Ѵ�.
                        //�޴� ��ȣ�� ���Է� ����ó���Ͽ� �Է¹޴´�.
                        while(1) {
                            if (scanf("%d", &songMenu) != 1){
                                printf("<ERROR> scanf error\n");
                                while(getchar() != '\n');
                                continue;
                                }
                            break;
                        }
                        if (songMenu == 1){
                            editSong(song); //�뷡�� �����Ѵ�.
                        }
                        else if (songMenu == 2){
                            deleteSong(&sl, song); //�뷡�� �����Ѵ�.
                        }
                        else if (songMenu == 0){
                            break; //�ٽ� ó���޴��� ���ư���.
                        }
                        break;
                    }
                }
            }
            if (count == 0) //�´� �뷡�� �ϳ��� ���ٸ� �޽����� ����Ѵ�.
                printf("No song like that!\n");
        }
        else if (menu == 2){
            addSong(&sl); //�뷡�� �߰��Ѵ�.
        }
        else if (menu == 3){
            printAllSongs(sl); //��� �뷡�� ����Ѵ�.
        }
        else if (menu == 4){
            printf("Are you sure? (y or n)\n"); //�ǻ縦 �ѹ��� �����Ѵ�.
            scanf(" %c", &ans);
            if (ans == 'y'){
                deleteAll(&sl); //��� �뷡�� �����Ѵ�.
            }
        }
        else if (menu == 0){
            dataSave(sl); //�����͸� ���Ͽ� �����Ѵ�.
            //�޸� ����.
            free(sl.songs);
            free(song);
            break; //���α׷��� �����Ѵ�.
        }
    }
    return 0;
}

//���� ������� ���� �뷡����� �ҷ����� �Լ�
SongList dataLoad(void)
{
    SongList sl;
    char time[100][100], minute[50][50], second[50][50];
    char copy[50];
    char c;
    int num, ctr, i = 0;
    FILE * f = NULL;
    //������ ����.
    f = fopen("example.txt", "r");
    //������ ���µ� ������ ���ٸ� �޽����� ����Ѵ�.
    if (f == NULL) {
        printf("Open Error!\n");
        return ;
    }
    //�뷡 ������ �޾ƿ´�.
    fscanf(f, "%d", &num);
    //���๮�ڸ� �������ش�.
    fscanf(f, "\n");
    //capacity�� size�� �뷡������ �����ش�.
    sl.capacity = num;
    sl.size = num;
    //sl.songs�� �뷡������ŭ �����Ҵ� ���ش�.
    sl.songs = (Song *)malloc(num * sizeof(Song));
    //������ ���� �����Ҷ����� �ݺ��Ѵ�.
    while(!feof(f)){
        // ���๮�ڱ��� �̾�� ������ ������ ������ ������ �޾ƿ� �����Ѵ�.
        fgets(time[i], 50, f);
        fgets(sl.songs[i].artist, 50, f);
        fgets(sl.songs[i].title, 50, f);
        //���๮�ڸ� �������ش�.
        time[i][strlen(time[i])-1] = '\0';
        sl.songs[i].title[strlen(sl.songs[i].title)-1] = '\0';
        sl.songs[i].artist[strlen(sl.songs[i].artist)-1] = '\0';
        //time[i]�� �����صд�.
        strcpy(copy, time[i]);
        //time[i]�� ���⸦ �������� �߶� minute�� second�� ���� �������ش�.
        strcpy(minute[i], strtok(time[i], " "));
        strcpy(second[i], strtok(copy, " "));
        strcpy(second[i], strtok(NULL, " "));
        //minute[i]�� second[i]�� int���� �ٲ� �뷡��Ͽ� �������ش�.
        sl.songs[i].length.minute = atoi(minute[i]);
        sl.songs[i].length.second = atoi(second[i]);
        //�������� �����ϸ� ���๮�ڸ� �������ش�.
        if (i == num-1){
            fscanf(f, "\n");
        }
        i++; //�ѹ� �������� ���� �ε����� �Ѿ��.
    }
    //������ �ݾ��ش�.
    if (fclose(f) != 0){
        printf("Close Error!\n");
    }
    return sl; //�뷡����� �����Ѵ�.
}

//���Ͽ� �����͸� �����Ѵ�.
int dataSave(SongList sl)
{
    //������ ����.
    FILE* f = NULL;
    f=fopen("example.txt", "w");
    if (f == NULL) {
        printf("Open Error!\n");
        return -1;
    }
    //�뷡 ������ �޴´�.
    fprintf(f, "%d\n", sl.size);
    //��/�ʰ� ��� 0�� 0�ʰ� �ƴ϶�� �뷡����� �޴´�.
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

//�޴������ ����Ѵ�.
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

//�뷡 �Ѱ��� ����Ѵ�.
void printSong(Song* song)
{
    printf("\nTitle  : %s\n", song -> title);
    printf("Artist : %s\n", song -> artist);
    printf("Length : %d min %d sec\n", song -> length.minute, song -> length.second);
}

//1�� �޴��� ���� �޴������ ����Ѵ�.
void printSongMenu(void)
{
    printf("-------------------------------\n");
    printf("1. Edit\n");
    printf("2. Delete\n");
    printf("3. Previous\n");
    printf("-------------------------------\n");
}

//����ڰ� �Է��� �뷡�� ������ �뷡�� ã�� ������ش�.
Song* searchSong(SongList sl, char* title, char* artist)
{
    Song* song = NULL;
    //��� �뷡�� ���ư��� �˻��Ͽ� ����� ������ ��ġ�ϴ� �뷡�� ������ �� �뷡�� ����Ѵ�.
    for (int i = 0; i < sl.capacity; i++){
        if (strcmp(sl.songs[i].title , title) == 0){
            if (strcmp(sl.songs[i].artist, artist) == 0){
                song = &(sl.songs[i]);
                printSong(song);
                break;
            }
        }
    }
    return song; //ã�� �뷡 �Ѱ� �����͸� �����Ѵ�.
}

//�뷡�� �����Ѵ�.
int editSong(Song* song)
{
    char newTitle[100], newArtist[100];
    int min = 60, sec = 0;
    // �뷡 ����� ������ �Է¹޴´�.
    printf("Input new title: ");
    scanf(" %[^\n]s", newTitle);
    printf("input new artist: ");
    scanf(" %[^\n]s", newArtist);

    //�뷡 ����(��/��)�� �Է¹޴´�.
    while(1){
        printf("Input new length\n");
        printf("\t\tminute: ");
        scanf("%d", &min);
        //�ð��� 0���� 60������ ������ �ƴ϶�� �ٽ� �Է¹޴´�.
        if(min > 60 || min < 0){
            printf("<ERROR> editSong minute size\n");
            continue;
        }
        printf("\t\tsecond: ");
        scanf("%d", &sec);
        //�ð��� 0���� 60������ ������ �ƴ϶�� �ٽ� �Է¹޴´�.
        if(sec >= 60 || sec < 0){
            printf("<ERROR> editSong second size\n");
            continue;
        }
        break;
    }
    //�Ű������� ���� song������ �뷡������ �ٲپ� �������ش�.
    strcpy (song->title, newTitle);
    strcpy (song->artist, newArtist);
    song->length.minute = min;
    song->length.second = sec;
    return 0;
}

//�뷡 �� ���� �����Ѵ�.
int deleteSong(SongList* sl, Song* song)
{
    //size�� �ϳ� ���δ�.
    (sl->size)--;
    //�Ű������� ���� �뷡�� ��ġ�ϴ� ���� �ִٸ� ��/�ʸ� ��� 0���� �ٲ۴�.
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

//�뷡 �� ���� �߰��Ѵ�.
int addSong(SongList* sl)
{
    char newtitle[100], newartist[100];
    int min, sec, ctr = 0;
    (sl->size)++; //������ �߰��Ǿ� size�� �ϳ� �÷��ش�.
    ++(sl->capacity); //������ �߰��Ǿ� capacity�� �ϳ� �÷��ش�.
    //sl->songs�� ũ�⸦ 1��ŭ �÷��ش�.
    sl->songs = (Song *)realloc(sl->songs, (sl->capacity) * sizeof(Song));
    do{
        ctr = 0;
        //�뷡 ����� ������ �Է¹޴´�.
        printf("Input title: ");
        scanf(" %[^\n]s", newtitle);
        printf("Input artist: ");
        scanf(" %[^\n]s", newartist);
        //�Է¹��� �뷡�� ��ġ�ϴ� �뷡�� �ִٸ� �����޽����� ����Ѵ�.
        for (int i = 0; i < (sl->capacity); i++){
            if(strcmp(sl->songs[i].title, newtitle) == 0){
                if(strcmp((sl->songs[i]).artist, newartist) == 0){
                    ctr = 1;
                    printf("<ERROR> Already present\n");
                    break;
                }
            }
        }
    }while(ctr == 1); //��ġ�ϴ� �뷡�� �ִ� ��� ��� �ݺ��Ѵ�.

    //��, �ʰ� 60�ʸ� �Ѱų� ������ �Էµ��� �ʵ��� �Է¹޴´�.
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
    //sl->songs�� �þ ������ ���� �뷡������ �־��ش�.
    strcpy((sl->songs[(sl->capacity) - 1]).title, newtitle);
    strcpy((sl->songs[(sl->capacity) - 1]).artist, newartist);
    (sl->songs[(sl->capacity) - 1]).length.minute = min;
    (sl->songs[(sl->capacity) - 1]).length.second = sec;
    return 0;
}

//��� �뷡�� ����Ѵ�.
void printAllSongs(SongList sl)
{
    int ctr = 0; //����� �뷡�� �ִ��� ������ Ȯ���ϴ� ����
    //�ε����� �����ϸ� ��� �뷡�� ����Ѵ�.
    for(int i = 0; i < (sl.capacity); i++){
        if ((sl.songs[i].length.minute != 0) || (sl.songs[i].length.second != 0)){
            ctr ++;
            printf("%s - %s (%d:%d)\n", sl.songs[i].artist, sl.songs[i].title, sl.songs[i].length.minute, sl.songs[i].length.second);
        }
    }
    //����� �뷡�� �ϳ��� ���ٸ� �޽����� ����Ѵ�.
    if (ctr == 0){
        printf("No result\n");
    }
}

//��� �뷡�� �����Ѵ�.
int deleteAll(SongList* sl)
{
    //size�� 0���� ���ش�.
    (sl->size) = 0;
    //���ư��� ��� �뷡�� ��/�ʸ� 0�� 0�ʷ� �ٲ��ش�.
    for (int i = 0; i < (sl->capacity); i++){
        (sl->songs[i]).length.minute = 0;
        (sl->songs[i]).length.second = 0;
    }
    printf("...delete success\n");
}
