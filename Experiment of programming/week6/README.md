��������
����ָ����C++��׼���ṩ��һ�ֻ��ƣ����ڷ�ֹ�ڴ�й©����ʱ���ղ�����Ҫ���ڴ档
������ʹ����ͨ��ָ�����ʱ��һ���������߳����ӣ��������������ͷ��ڴ����������¿��õ��ڴ���١�
![1712144267890](image/README/1712144267890.png)
���ʹ������ָ�룬��ô����ָ���ڲ���ά��һ��ָ��ָ��Ŀ���ַ����һ��������ļ�����ָ�루�������ڴ��ϵĵ�ַ���޹�����ֻ���߼��ϵ���ϵ����������ͳ�Ƴ���Ŀ���ַ��ָ��������һ��������Ϊ0����ô�Ϳ�����Ϊû���κ�ָ����Է��ʵ��õ�ַ���õ�ַ�����ٱ���Ҫ����ʱ���Ϳ����ͷ��ڴ档
![alt text](dd411a36e0f836832b440d3ce841e0cc.JPG) ![alt text](34e37b54342c0bdc1c7052c7d5e7aa60.JPG)
���������ǾͲ���Ҫ�����ڴ���ͷţ���������ָ��ѡ���ں��ʵ�ʱ���ͷ��ڴ档
����Ҫ���㲹ȫһ��α����ָ����SmartPointer��Ϊ�˼�����������и�����ָ����ֻ��ָ��̬�����ڴ��Node���͵Ķ��󣬲���һ��Node�����ַֻ�����ڳ�ʼ��һ������ָ�루Node���������Ƕ����ռλ���ͣ�һ��Node�����ʾһ����ҪSmartPointer�����Ŀռ䣩��
����ָ�����ڲ�ά�������ؼ���Ա������
         Node* pointer;
         int* ref_cnt;
        Node���͵�ָ�����pointer��
        һ��ָ�����ͱ�����ָ��ref_cnt����ָ���ֵ*ref_cnt��ʾ��ǰӵ��pointer��ָ���Node�����ַ��SmartPointer��������
��ָ������������Ҫ����ɵĳ�Ա������
        �������캯����ʹ��һ��SmartPointer��������ʼ��������
        assign�������ú�������һ��SmartPointer����sptr�������������pointerָ�븳ֵΪsptr.pointer��
        �������������ٱ�SmartPoiner����Ҳ����˵���������ٳ���pointerָ��ָ���Node��ַ��ע�⣺Ϊͨ��������������Ҫ��֤�����������Ա��ظ����á�
����Ҫ��ʵ�ֵĹ����У�ά��������Ա������ֵ���������Ҫ˼�������������У�ref_cntӦ����θ�ֵ�͸ı䣬ʹ�ö����κ�Node�������û��SmartPointer����������ַ��������еĿռ䱻�ͷ�(����*ref_cntΪ0��ʱ���ͷ�pointerָ���Node����)��
���
�����ļ��������Node��������������Ӧ��id��˳�����жϳ����Ƿ���ȷ�������뾡����Ҫ�޸�ͷ�ļ����ݡ�
����1
        SmartPointer sp1(new Node(1));
        //������������ʱnode1Ӧ�ñ�����
�����
1
����2
        SmartPointer sp1(new Node(1));
        SmartPointer* sp2=new SmartPointer(sp1);
        //����������sp1�����٣���ʱsp2�Գ���node1�ĵ�ַ��node1��������
�����

����3
        SmartPointer sp1(new Node(123));
        sp1.~SmartPointer();
        sp1.assign(SmartPointer());//���Կ�ָ�븳ֵ
        sp1.assign(*(new SmartPointer(new Node(456))));//Node 456��Ȼ���ѿռ��е�ĳ��ָ����У����Բ��ᱻ�ͷ�
���
123
��ʾ
        ��ע������³���ԣ���������ܵ��³�������Ĵ��룬��ô�Ϳ��ܲ�ͨ��������������������ϸ˼�����������������Ǹ��ֿ��ܳ��ֿ�ָ��������
        �벻Ҫ�ڴ����ļ��а���"shared_ptr"�ֶΣ����ǽ��ڲ���ʱ���м�⡣