#include "landlord.h"

Repairinfo repairInfo;

bool cmpRepair(RepairinfoSt a, RepairinfoSt b)
{
    return a.date < b.date;
}

Repairinfo::Repairinfo()
{
    fstream file;
    file.open("repairinfo.txt", ios::in);
    for (int i = 0; !file.eof(); i++)
    {
        vec.push_back({});
        file >> vec[i].date >> vec[i].reporter >> vec[i].description >> vec[i].status >> vec[i].comment;
    }
    file.close();
    rpTitle = vec[0];
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if (i->date == "")
        {
            i--;
            vec.erase(i + 1);
        }
    }

    sort(vec.begin() + 1, vec.end(), cmpRepair);
    update();
}

Repairinfo::~Repairinfo()
{
    update();
}

void Repairinfo::show(string status)
{
    system("cls");
    pos(30, 4);
    cout << "**********ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��0�鿴ȫ�� ��1�鿴�Ѵ��� ��2�鿴δ����           " << endl;
    pos(30, 8);
    cout << "* ��q���ط����˵�                " << endl;
    pos(30, 10);
    cout << "* ��r�޸�ά��״̬  ��dɾ��ά��״̬ " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    pos(10, 14);
    cout << status << endl;

    int order = 0;
    if (status == "ȫ��")
        for (auto i : vec)
        {
            pos(10, 15 + order);
            cout.setf(ios::left); // ���ö��뷽ʽΪleft
            if (order == 0)
                cout << setw(10) << "���" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            else
            {
                cout << setw(10) << order << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            }

            order++;
        }
    else
        for (auto i : vec)
        {
            if (order == 0)
            {
                pos(10, 15 + order);
                cout << setw(10) << "���" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
                order++;
            }
            else if (i.status == status)
            {
                pos(10, 15 + order);
                cout.setf(ios::left);                                                                                                                                            // ���ö��뷽ʽΪleft
                cout << setw(10) << order << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());

                order++;
            }
        }
}

void Repairinfo::update()
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if (i->date == "")
        {
            i--;
            vec.erase(i + 1);
        }
    }
    fstream file;
    file.open("repairinfo.txt", ios::out);
    for (auto i : vec)
    {
        file << i.date << ' ' << i.reporter << ' ' << i.description << ' ' << i.status << ' ' << i.comment << endl;
    }
    file.close();
}



void Repairinfo::showDeleteInterface()
{
    system("cls");
    pos(30, 4);
    cout << "**********ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��aȫɾ ��yɾ���Ѵ��� " << endl;
    pos(30, 8);
    cout << "* ��r������һ��" << endl;
    pos(30, 10);
    cout << "* ��������Ҫɾ������Ϣ���        " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    int order = 0;
    show();
    pos(30, 11);
    cin >> keys;
}

void Repairinfo::DeleteRepairInfo()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        showDeleteInterface();
        if (isnumber(keys) && stoi(keys) <= vec.size())
        {
            int position = stoi(keys);
            vec.erase(vec.begin() + position);
            update();
        }
        else
            switch (keys[0])
            {
            case 'r':
                flag = 0;
                break;
            case 'a':
                vec.clear();
                vec.push_back(rpTitle);
                update();
                break;
            case 'y':
                for (auto i = vec.begin(); i != vec.end(); i++)
                {
                    if (i->status == "�Ѵ���")
                    {
                        i--;
                        vec.erase(i + 1);
                    }
                }
                update();
                break;

            default:
                pos(30, 2);
                cout << "��������,����������" << endl;
                break;
            }
    }

    keyc = 0;
}

void Repairinfo::showReviseInterface()
{
    system("cls");
    pos(30, 4);
    cout << "**********ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��r������һ��" << endl;
    pos(30, 8);
    cout << "* ��������Ҫ�޸ĵ���Ϣ���" << endl;
    pos(30, 10);
    cout << "********************************************" << endl;
    int order = 0;
    show();
    pos(30, 9);
    cin >> keys;
}

void Repairinfo::ReviseRepairChoose()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        showReviseInterface();

        if (isnumber(keys) && stoi(keys) <= vec.size())
        {
            ReviseRepairInfo();
        }
        else
        {
            pos(30, 2);
            cout << "��������,����������" << endl;
            pos(30, 3);
            system("pause");
        }
    }

    keyc = 0;
}

void Repairinfo::showReviseInfo()
{
    system("cls");
    pos(30, 4);
    cout << "*****************ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��s�޸�״̬ ��c�޸ı�ע  " << endl;
    pos(30, 10);
    cout << "* ��b����              " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    pos(10, 14);
    cout << setw(10) << "���" << setw(10) << rpTitle.date << setw(10) << rpTitle.reporter << setw(30) << rpTitle.description << setw(10) << rpTitle.status << setw(30) << rpTitle.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
    pos(10, 15);
    keynum = stoi(keys);
    cout << setw(10) << keys << setw(10) << vec[keynum].date << setw(10) << vec[keynum].reporter << setw(30) << vec[keynum].description << setw(10) << vec[keynum].status << setw(30) << vec[keynum].comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
}

void Repairinfo::ReviseRepairInfo()
{
    char revisekey = 0;
    bool flag = 1;
    while (flag)
    {
        showReviseInfo();
        revisekey = _getch();

        if (revisekey == 's')
        {
            if (vec[keynum].status == "�Ѵ���")
                vec[keynum].status = "δ����";
            else
                vec[keynum].status = "�Ѵ���";
            update();
            break;
        }
        if (revisekey == 'c')
        {
            pos(30, 18);
            cout << "�����뱸ע(��������ո��ֱ�ӻس�):" << endl;
            pos(30, 19);
            string comment = "";
            cin >> comment;
            cin.clear();
            if (comment == "")
                comment = "��";
            vec[keynum].comment = comment;
            update();
            break;
        }
        if (revisekey == 'b')
        {
            break;
        }
        else
        {
            pos(30, 2);
            cout << "��������,����������          " << endl;
            pos(30, 3);
            system("pause");
        }
    }
    update();
}

