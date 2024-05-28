#include "landlord.h"

Repairinfo::Repairinfo()
{
    rpTitle = {"����", "�����û�", "����", "����", "״̬", "��ע", "ά�޷�"};
    fstream file;
    file.open("repairinfo.txt", ios::in);
    for (int i = 0; !file.eof(); i++)
    {
        vec.push_back({});
        file >> vec[i];
    }
    file.close();
    if (vec.size() == 1 && vec[0].room == "")
    {
        vec.clear();
    }
    else
    {
        for (auto i = vec.begin(); !vec.empty() && i != vec.end(); i++)
        {
            if (i->room == "")
            {
                i--;
                vec.erase(i + 1);
            }
        }
    }
    update();
}

Repairinfo::~Repairinfo()
{
    update();
}

void Repairinfo::show(string status)
{
    system("cls");
    showNow();
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

    int order = 1;
    pos(10, 15);
    cout.setf(ios::left); // ���ö��뷽ʽΪleft

    cout << setw(10) << "���" << rpTitle << endl;

    if (status == "ȫ��")
        for (auto i : vec)
        {
            pos(10, 15 + order);
            cout << setw(10) << order << i;

            order++;
        }
    else
        for (auto i : vec)
        {
            if (i.status == status)
            {
                pos(10, 15 + order);
                cout.setf(ios::left); // ���ö��뷽ʽΪleft
                cout << setw(10) << order << i;
                order++;
            }
        }
}

void Repairinfo::update()
{
    if (!vec.empty())
    {
        sort(vec.begin() + 1, vec.end(), [](RepairinfoSt a, RepairinfoSt b)
             { return a.date < b.date; });
        for (auto i = vec.begin(); i != vec.end(); i++)
        {
            if (i->room == "")
            {
                i--;
                vec.erase(i + 1);
            }
        }
    }

    ofstream file;
    file.open("repairinfo.txt");
    for (auto i : vec)
    {
        file << i;
    }
    file.close();
}

void Repairinfo::showDeleteInterface()
{
    system("cls");
    showNow();
    show();
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
            vec.erase(vec.begin() + position - 1);
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
                flag = 0;
                break;
            }
    }

    keyc = 0;
}

void Repairinfo::showReviseInterface()
{
    system("cls");
    showNow();
    pos(30, 4);
    cout << "**********ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��r������һ��" << endl;
    pos(30, 8);
    cout << "* ��������Ҫ�޸ĵ���Ϣ���" << endl;
    pos(30, 10);
    cout << "********************************************" << endl;
    pos(10, 15);
    cout.setf(ios::left);
    cout << setw(10) << "���" << rpTitle;
    int order = 1;
    for (auto i : vec)
    {
        pos(10, 15 + order);
        cout << setw(10) << order << i;
        order++;
    }
}

void Repairinfo::ReviseRepairChoose()
{
    keys = "";
    bool flag = 1;
    while (flag)
    {
        showReviseInterface();
        pos(30, 9);

        cin >> keys;
        // ��������Ƿ�Ϊ����
        if (isnumber(keys) && stoi(keys) <= vec.size())
        {
            keynum = stoi(keys) - 1;
            ReviseRepairInfo();
        }
        else if (keys[0] == 'r')
        {
            flag = 0;
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
    showNow();
    pos(30, 4);
    cout << "*****************ά����Ϣ�鿴*******************" << endl;
    pos(30, 6);
    cout << "* ��s�޸�״̬ ��c�޸ı�ע " << endl;
    pos(30, 10);
    cout << "* ��b����              " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    pos(10, 14);
    cout.setf(ios::left);
    cout << setw(10) << "���" << rpTitle;
    pos(10, 15);
    cout << setw(10) << keys << vec[stoi(keys) - 1];
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
            {
                vec[keynum].status = "�Ѵ���";
                while (true)
                {
                    pos(30, 6);
                    cout << "* ������ά�޷���          " << endl;
                    pos(30, 7);

                    cin >> vec[keynum].money;

                    if (!isnumber(vec[keynum].money))
                    {
                        pos(30, 6);
                        cout << "* ��������,����������" << endl;
                        pos(32, 7);
                        system("pause");
                    }
                    else
                    {
                        Date today;
                        moneyInfo.vec.push_back({today, '-' + vec[keynum].money, to_string(vec[keynum].date) + "_" + vec[keynum].room + vec[keynum].description + "_ά�޷�"});
                        moneyInfo.update();
                        break;
                    }
                }
            }
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
