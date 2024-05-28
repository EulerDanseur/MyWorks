#include "landlord.h"

Repairinfo::Repairinfo()
{
    rpTitle = {"日期", "报告用户", "房间", "问题", "状态", "备注", "维修费"};
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
    cout << "**********维修信息查看*******************" << endl;
    pos(30, 6);
    cout << "* 按0查看全部 按1查看已处理 按2查看未处理           " << endl;
    pos(30, 8);
    cout << "* 按q返回房主菜单                " << endl;
    pos(30, 10);
    cout << "* 按r修改维修状态  按d删除维修状态 " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    pos(10, 14);
    cout << status << endl;

    int order = 1;
    pos(10, 15);
    cout.setf(ios::left); // 设置对齐方式为left

    cout << setw(10) << "序号" << rpTitle << endl;

    if (status == "全部")
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
                cout.setf(ios::left); // 设置对齐方式为left
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
    cout << "**********维修信息查看*******************" << endl;
    pos(30, 6);
    cout << "* 按a全删 按y删除已处理 " << endl;
    pos(30, 8);
    cout << "* 按r返回上一级" << endl;
    pos(30, 10);
    cout << "* 请输入您要删除的信息序号        " << endl;
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
                    if (i->status == "已处理")
                    {
                        i--;
                        vec.erase(i + 1);
                    }
                }
                update();
                break;

            default:
                pos(30, 2);
                cout << "输入有误,请重新输入" << endl;
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
    cout << "**********维修信息查看*******************" << endl;
    pos(30, 6);
    cout << "* 按r返回上一级" << endl;
    pos(30, 8);
    cout << "* 请输入您要修改的信息序号" << endl;
    pos(30, 10);
    cout << "********************************************" << endl;
    pos(10, 15);
    cout.setf(ios::left);
    cout << setw(10) << "序号" << rpTitle;
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
        // 检查输入是否为数字
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
            cout << "输入有误,请重新输入" << endl;
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
    cout << "*****************维修信息查看*******************" << endl;
    pos(30, 6);
    cout << "* 按s修改状态 按c修改备注 " << endl;
    pos(30, 10);
    cout << "* 按b返回              " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    pos(10, 14);
    cout.setf(ios::left);
    cout << setw(10) << "序号" << rpTitle;
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
            if (vec[keynum].status == "已处理")
                vec[keynum].status = "未处理";
            else
            {
                vec[keynum].status = "已处理";
                while (true)
                {
                    pos(30, 6);
                    cout << "* 请输入维修费用          " << endl;
                    pos(30, 7);

                    cin >> vec[keynum].money;

                    if (!isnumber(vec[keynum].money))
                    {
                        pos(30, 6);
                        cout << "* 输入有误,请重新输入" << endl;
                        pos(32, 7);
                        system("pause");
                    }
                    else
                    {
                        Date today;
                        moneyInfo.vec.push_back({today, '-' + vec[keynum].money, to_string(vec[keynum].date) + "_" + vec[keynum].room + vec[keynum].description + "_维修费"});
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
            cout << "请输入备注(请勿输入空格或直接回车):" << endl;
            pos(30, 19);
            string comment = "";

            cin >> comment;

            if (comment == "")
                comment = "无";
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
            cout << "输入有误,请重新输入          " << endl;
            pos(30, 3);
            system("pause");
        }
    }
    update();
}
