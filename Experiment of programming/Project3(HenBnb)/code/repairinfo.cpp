#include "housing.h"

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
    cout << "* ��q���ط����˵�                          " << endl;
    pos(30, 10);
    cout << "* ��r�޸�ά��״̬                   " << endl;
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
                cout.setf(ios::left);  // ���ö��뷽ʽΪleft
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


void Housing::DoRepairInfo()
{
    repairInfo.show("ȫ��");
    key = 0;
    bool flag = 1;
    while (flag)
    {
        key = _getch();
        switch (key)
        {
        case '0':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            repairInfo.show("ȫ��");
            break;
        case '1':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            repairInfo.show("�Ѵ���");
            break;
        case '2':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            repairInfo.show("δ����");
            break;
        case 'd':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                DeleteRepairInfo();
            break;
        case 'r':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "�����б�Ϊ��" << endl;
            }
            else
                ReviseRepairInfo();
            break;
        case 'q':
            Menu();
            flag = 0;
            break;
        case 'e':
            showMainMenu();
            flag = 0;
            break;
        default:
            pos(30, 2);
            cout << "��������,����������" << endl;
            break;
        }
    }
}



void Housing::ShowDeleteRepairInfo()
{
    system("cls");
    pos(30, 2);
    cout << "��������Ҫɾ������Ϣ���" << endl;
    pos(30, 4);
    cout << "**********ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��aȫɾ ��yɾ���Ѵ��� " << endl;
    pos(30, 8);
    cout << "* ��q���ط����˵�  ��e����������" << endl;
    pos(30, 10);
    cout << "* ��0�˳�ɾ������                    " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    int order = 0;
    for (auto i : repairInfo.vec)
    {

        pos(10, 14 + order);
        cout.setf(ios::left); // ���ö��뷽ʽΪleft
        if (order == 0)
            cout << setw(10) << "���" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
        else
            cout << setw(10) << order << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());

        order++;
    }
}

void Housing::DeleteRepairInfo()
{
    ShowDeleteRepairInfo();
    key = 0;
    bool flag = 1;
    while (flag)
    {
        key = _getch();
        if (key == '0')
        {
            repairInfo.show("ȫ��");
            DoRepairInfo();
            break;
        }
        if (key != '0' && isdigit(key) && key - '0' <= repairInfo.vec.size())
        {
            int position = key - '0';
            // auto ite = repairInfo.vec.begin() + position;
            repairInfo.vec.erase(repairInfo.vec.begin() + position);
            repairInfo.update();
            ShowDeleteRepairInfo();
        }
        else
            switch (key)
            {
            case 'q':
                Menu();
                flag = 0;
                break;
            case 'e':
                showMainMenu();
                flag = 0;
                break;
            case 'a':
                repairInfo.vec.clear();
                repairInfo.vec.push_back(repairInfo.rpTitle);
                repairInfo.update();
                break;
            case 'y':
                for (auto i = repairInfo.vec.begin(); i != repairInfo.vec.end(); i++)
                {
                    if (i->status == "�Ѵ���")
                    {
                        i--;
                        repairInfo.vec.erase(i + 1);
                    }
                }
                repairInfo.update();
                ShowDeleteRepairInfo();
                break;

            default:
                pos(30, 2);
                cout << "��������,����������" << endl;
                break;
            }
    }

    key = 0;
}

void Housing::ReviseRepairInfo()
{


    key = 0;
    while (key != 'q' && key != 'e')
    {
        system("cls");
        pos(30, 2);
        cout << "��������Ҫ�޸ĵ���Ϣ���" << endl;
        pos(30, 4);
        cout << "*****************ά����Ϣ�鿴*******************" << endl;
        pos(30, 6);
        cout << "*  " << endl;
        pos(30, 8);
        cout << "* ��q���ط����˵�  ��e����������  ��0�˳��޸Ĳ���" << endl;
        pos(30, 10);
        cout << "*               " << endl;
        pos(30, 12);
        cout << "********************************************" << endl;
        int order = 0;
        for (auto i : repairInfo.vec)
        {

            pos(10, 14 + order);
            cout.setf(ios::left); // ���ö��뷽ʽΪleft
            if (order == 0)
                cout << setw(10) << "���" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            else
                cout << setw(10) << order << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());

            order++;
        }

        key = _getch();


        if (key == '0')
        {
            repairInfo.show("ȫ��");
            DoRepairInfo();
            break;
        }
        if (key != '0' && isdigit(key) && key - '0' <= repairInfo.vec.size())
        {
            system("cls");
            pos(30, 2);
            cout << "��s�޸�״̬ ��c�޸ı�ע ��b����" << endl;
            pos(30, 4);
            cout << "*****************ά����Ϣ�鿴*******************" << endl;
            pos(30, 6);
            cout << "*  " << endl;
            pos(30, 10);
            cout << "*               " << endl;
            pos(30, 12);
            cout << "********************************************" << endl;
            pos(10, 14);
            cout << setw(10) << "���" << setw(10) << repairInfo.rpTitle.date << setw(10) << repairInfo.rpTitle.reporter << setw(30) << repairInfo.rpTitle.description << setw(10) << repairInfo.rpTitle.status << setw(30) << repairInfo.rpTitle.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            pos(10, 15);
            cout << setw(10) << key - '0' << setw(10) << repairInfo.vec[key - '0'].date << setw(10) << repairInfo.vec[key - '0'].reporter << setw(30) << repairInfo.vec[key - '0'].description << setw(10) << repairInfo.vec[key - '0'].status << setw(30) << repairInfo.vec[key - '0'].comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            char revisekey = 0;

            while (revisekey != 's' && revisekey != 'c' && revisekey != 'b')
            {
                revisekey = _getch();

                if (revisekey == 's')
                {
                    if (repairInfo.vec[key - '0'].status == "�Ѵ���")
                        repairInfo.vec[key - '0'].status = "δ����";
                    else
                        repairInfo.vec[key - '0'].status = "�Ѵ���";
                    repairInfo.update();
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
                    repairInfo.vec[key - '0'].comment = comment;
                    repairInfo.update();
                    break;
                }
                if (revisekey == 'b')
                {
                    break;
                }
            }
            repairInfo.update();
        }
        else if (key == 'q')
        {
            Menu();
            break;
        }
        else if (key == 'e')
        {
            showMainMenu();
            break;
        }
        else
        {
            pos(30, 2);
            cout << "��������,����������             " << endl;
            pos(30, 3);
            system("pause");
        }
    }


    key = 0;
}


