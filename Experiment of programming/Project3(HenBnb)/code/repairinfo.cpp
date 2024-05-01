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
    cout << "**********维修信息查看*******************" << endl;
    pos(30, 6);
    cout << "* 按0查看全部 按1查看已处理 按2查看未处理           " << endl;
    pos(30, 8);
    cout << "* 按q返回房主菜单                          " << endl;
    pos(30, 10);
    cout << "* 按r修改维修状态                   " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    pos(10, 14);
    cout << status << endl;

    int order = 0;
    if (status == "全部")
        for (auto i : vec)
        {
            pos(10, 15 + order);
            cout.setf(ios::left); // 设置对齐方式为left
            if (order == 0)
                cout << setw(10) << "序号" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
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
                cout << setw(10) << "序号" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
                order++;
            }
            else if (i.status == status)
            {
                pos(10, 15 + order);
                cout.setf(ios::left);  // 设置对齐方式为left
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
    repairInfo.show("全部");
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
                cout << "修理列表为空" << endl;
            }
            repairInfo.show("全部");
            break;
        case '1':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            repairInfo.show("已处理");
            break;
        case '2':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            repairInfo.show("未处理");
            break;
        case 'd':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
            }
            else
                DeleteRepairInfo();
            break;
        case 'r':
            if (repairInfo.vec.size() == 1)
            {
                pos(30, 2);
                cout << "修理列表为空" << endl;
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
            cout << "输入有误,请重新输入" << endl;
            break;
        }
    }
}



void Housing::ShowDeleteRepairInfo()
{
    system("cls");
    pos(30, 2);
    cout << "请输入您要删除的信息序号" << endl;
    pos(30, 4);
    cout << "**********维修信息查看*******************" << endl;
    pos(30, 6);
    cout << "* 按a全删 按y删除已处理 " << endl;
    pos(30, 8);
    cout << "* 按q返回房主菜单  按e返回主界面" << endl;
    pos(30, 10);
    cout << "* 按0退出删除操作                    " << endl;
    pos(30, 12);
    cout << "********************************************" << endl;
    int order = 0;
    for (auto i : repairInfo.vec)
    {

        pos(10, 14 + order);
        cout.setf(ios::left); // 设置对齐方式为left
        if (order == 0)
            cout << setw(10) << "序号" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
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
            repairInfo.show("全部");
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
                    if (i->status == "已处理")
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
                cout << "输入有误,请重新输入" << endl;
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
        cout << "请输入您要修改的信息序号" << endl;
        pos(30, 4);
        cout << "*****************维修信息查看*******************" << endl;
        pos(30, 6);
        cout << "*  " << endl;
        pos(30, 8);
        cout << "* 按q返回房主菜单  按e返回主界面  按0退出修改操作" << endl;
        pos(30, 10);
        cout << "*               " << endl;
        pos(30, 12);
        cout << "********************************************" << endl;
        int order = 0;
        for (auto i : repairInfo.vec)
        {

            pos(10, 14 + order);
            cout.setf(ios::left); // 设置对齐方式为left
            if (order == 0)
                cout << setw(10) << "序号" << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            else
                cout << setw(10) << order << setw(10) << i.date << setw(10) << i.reporter << setw(30) << i.description << setw(10) << i.status << setw(30) << i.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());

            order++;
        }

        key = _getch();


        if (key == '0')
        {
            repairInfo.show("全部");
            DoRepairInfo();
            break;
        }
        if (key != '0' && isdigit(key) && key - '0' <= repairInfo.vec.size())
        {
            system("cls");
            pos(30, 2);
            cout << "按s修改状态 按c修改备注 按b返回" << endl;
            pos(30, 4);
            cout << "*****************维修信息查看*******************" << endl;
            pos(30, 6);
            cout << "*  " << endl;
            pos(30, 10);
            cout << "*               " << endl;
            pos(30, 12);
            cout << "********************************************" << endl;
            pos(10, 14);
            cout << setw(10) << "序号" << setw(10) << repairInfo.rpTitle.date << setw(10) << repairInfo.rpTitle.reporter << setw(30) << repairInfo.rpTitle.description << setw(10) << repairInfo.rpTitle.status << setw(30) << repairInfo.rpTitle.comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            pos(10, 15);
            cout << setw(10) << key - '0' << setw(10) << repairInfo.vec[key - '0'].date << setw(10) << repairInfo.vec[key - '0'].reporter << setw(30) << repairInfo.vec[key - '0'].description << setw(10) << repairInfo.vec[key - '0'].status << setw(30) << repairInfo.vec[key - '0'].comment << endl; // printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", order, i.date.c_str(), i.reporter.c_str(), i.description.c_str(), i.status.c_str(),i.comment.c_str());
            char revisekey = 0;

            while (revisekey != 's' && revisekey != 'c' && revisekey != 'b')
            {
                revisekey = _getch();

                if (revisekey == 's')
                {
                    if (repairInfo.vec[key - '0'].status == "已处理")
                        repairInfo.vec[key - '0'].status = "未处理";
                    else
                        repairInfo.vec[key - '0'].status = "已处理";
                    repairInfo.update();
                    break;
                }
                if (revisekey == 'c')
                {
                    pos(30, 18);
                    cout << "请输入备注(请勿输入空格或直接回车):" << endl;
                    pos(30, 19);
                    string comment = "";
                    cin >> comment;
                    cin.clear();
                    if (comment == "")
                        comment = "无";
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
            cout << "输入有误,请重新输入             " << endl;
            pos(30, 3);
            system("pause");
        }
    }


    key = 0;
}


