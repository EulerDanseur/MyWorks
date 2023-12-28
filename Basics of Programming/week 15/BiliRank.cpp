#include <iostream>
#include <cstring>
using namespace std;
typedef struct VideoNode
{
    int id;            //视频的id，每个视频都有一个唯一的id
    char label[20];        //视频所属的分区，表示视频的类别
    int visit;            //该视频的浏览量
    int liked;            //视频获得的点赞数
    int collection;        //视频获得的收藏数
    int coins;            //视频获得的投币数
    int score;            //视频的综合得分
    VideoNode* next;    //指向下一个视频
}VideoNode;

VideoNode *head;
void Printrank(char lab[20]);
void AddInfo(int id);
VideoNode *Insertnode(VideoNode *head, VideoNode *temp);
int main()
{   
    int n;
    cin >> n;
    bool t;
    int id;
    char label[20]={0};
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        if(t)
        {
            cin >> label;
            Printrank(label);
        }
        else
        {
            cin >> id;
            AddInfo(id);
        }
    }

    return 0;
}

void AddInfo(int idx)
{
    bool existed = 0, like = 0, collect = 0;
    int coin = 0;
    char lab[20];
    for(VideoNode *cur = head; cur; cur = cur->next)
    {
        if(cur->id == idx)
        {
            existed = 1;
            cin >> like >> collect >> coin >> lab;
            cur->visit++;
            cur->liked += like;
            cur->collection += collect;
            cur->coins += coin;
            cur->score += 1 + like*2 + collect*3 + coin*4;
            break; 
        }
    }
    if(!existed)
    {
        VideoNode *cur = new VideoNode;
        cur->next = head;
        head = cur;
        cin >> like >> collect >> coin >> lab;
        cur->id = idx;
        cur->visit = 1;
        cur->liked = like;
        cur->collection = collect;
        cur->coins = coin;
        cur->score = 1 + like*2 + collect*3 + coin*4;
        strcpy(cur->label, lab);
    }
}

void Printrank(char lab[20])
{
    VideoNode *rankhead = NULL;
    VideoNode *temp = NULL;
    for(VideoNode *cur = head; cur; cur = cur->next)
    {
        if(strcmp(cur->label, lab) == 0)
        {
            temp = new VideoNode;
            *temp = *cur;
            temp->next = NULL;
            if(!rankhead) 
                rankhead = temp;
            else
                rankhead = Insertnode(rankhead, temp);
        }
    }

    while(rankhead)
    {
        cout << rankhead->id << ' '<< rankhead->score << endl;
        rankhead = rankhead->next;
    }
}

VideoNode *Insertnode(VideoNode *rankhead, VideoNode *temp)
{
    if(temp->score > rankhead->score)
    {
        temp->next = rankhead;
        rankhead = temp;
        return rankhead;
    }
    else if(temp->score == rankhead->score)
    {
        if(temp->id < rankhead->id)
        {
            temp->next = rankhead;
            rankhead = temp;
            return rankhead;
        }

        VideoNode *prev = rankhead;
        VideoNode *current = rankhead;
        while(current && current->id < temp->id)
        {
            prev = current;
            current = current->next;
        }
        temp->next = current;
        prev->next = temp;
        return rankhead;
    }

    VideoNode *prev = rankhead;
    VideoNode *current = rankhead;
    while(current && current->score > temp->score)
    {
        prev = current;
        current = current->next;
    }
    temp->next = current;
    prev->next = temp;
    return rankhead;
}

