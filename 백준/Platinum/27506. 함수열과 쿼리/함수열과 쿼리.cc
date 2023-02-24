#include <iostream>
#define MAX_N 100002

using namespace std;

struct _Node{
    int start;
    int end;
    int func[6];
}typedef Node;

int n;
int inp[MAX_N][6];
Node tree[4*MAX_N+1];

void seg_init(int s, int e, int idx)
{
    tree[idx].start = s;
    tree[idx].end = e;
    if(s == e)
    {
        for(int i=1; i<=5; i++)
            tree[idx].func[i] = inp[s][i];
        return;
    }

    int mid = (s+e)/2;
    int left = 2*idx+1;
    int right = 2*idx+2;

    seg_init(s, mid, left);
    seg_init(mid+1, e, right);

    int(&hereFunc)[6] = tree[idx].func;
    int(&leftFunc)[6] = tree[left].func;
    int(&rightFunc)[6] = tree[right].func;

    for(int i=1; i<=5; i++)
    {
        hereFunc[i] = leftFunc[rightFunc[i]];
    }
}

void get_func(int s, int e, int idx, int(&ret)[6])
{
//    cout << s << " " << e << " " << idx << '\n';
    Node& here = tree[idx];
    if(here.start == s && here.end == e)
    {
        for(int i=1; i<=5; i++)
        {
            ret[i] = here.func[i];
        }
        return;
    }

    int mid = (here.start + here.end) / 2;
    if(e <= mid) return get_func(s, e, 2*idx+1, ret);
    else if(mid < s) return get_func(s, e, 2*idx+2, ret);
    else
    {
        int leftFunc[6];
        get_func(s, mid, 2*idx+1, leftFunc);
        int rightFunc[6];
        get_func(mid+1, e, 2*idx+2, rightFunc);
        for(int i=1; i<=5; i++)
        {
            ret[i] = leftFunc[rightFunc[i]];
        }
    }
}

void update(int& target, int idx, int(&temp)[6])
{
    Node& here = tree[idx];
    if(here.start == here.end && here.start == target)
    {
        for(int i=1; i<=5; i++)
        {
            here.func[i] = temp[i];
        }
        return;
    }

    int mid = (here.start + here.end) / 2;
    if(target <= mid)
    {
        update(target, 2*idx+1, temp);
    }
    else
    {
        update(target, 2*idx+2, temp);
    }

    int(&hereFunc)[6] = tree[idx].func;
    int(&leftFunc)[6] = tree[2*idx+1].func;
    int(&rightFunc)[6] = tree[2*idx+2].func;
//    cout << here.start << " " << here.end << '\n';
    for(int i=1; i<=5; i++)
    {
        hereFunc[i] = leftFunc[rightFunc[i]];
//        cout << hereFunc[i] << " ";
    }
//    cout << '\n';
}

void get_inverse(int(&temp)[6])
{
    int ret[6];
    for(int i=1; i<=5; i++)
    {
        ret[temp[i]] = i;
    }
    for(int i=1; i<=5; i++)
    {
        temp[i] = ret[i];
    }
}

void print_funcs(int idx)
{
    Node& here = tree[idx];
    if(here.start == here.end)
    {
        cout << here.start << ": ";
        for(int i=1; i<=5; i++)
        {
            cout << here.func[i] << " ";
        }
        cout << '\n';
        return;
    }

    print_funcs(2*idx+1);
    print_funcs(2*idx+2);
}

void query(int target, int s, int e, int(&temp)[6])
{
    int test[6];
    get_func(s, e, 0, test);
    int hereFunc[6];
    get_func(target, target, 0, hereFunc);

    bool isOk = true;
    for(int i=1; i<=5; i++)
    {
        if(test[i] != temp[i])
        {
            isOk = false;
            break;
        }
    }

    if(!isOk)
    {
        if(s == target && e == target)
        {        
            for(int i=1; i<=5; i++)
            {
                hereFunc[i] = temp[i];
            }
        }
        else if(s == target)
        {
            int rightFunc[6];
            get_func(target+1, e, 0, rightFunc);
            for(int i=1; i<=5; i++)
            {
                hereFunc[rightFunc[i]] = temp[i];
            }
        }
        else if(e == target)
        {
            int leftFunc[6];
            get_func(s, target-1, 0, leftFunc);
            get_inverse(leftFunc);
            for(int i=1; i<=5; i++)
            {
                hereFunc[i] = leftFunc[temp[i]];
            }
        }
        else
        {
            int leftFunc[6];
            get_func(s, target-1, 0, leftFunc);
            get_inverse(leftFunc);
            int rightFunc[6];
            get_func(target+1, e, 0, rightFunc);
            for(int i=1; i<=5; i++)
            {
                hereFunc[rightFunc[i]] = leftFunc[temp[i]];
            }
        }
        update(target, 0, hereFunc);
    }

//    cout << "Query " << target << " " << s << " " << e << "\n";
    for(int i=1; i<=5; i++)
    {
        cout << hereFunc[i] << " ";
    }
    cout << '\n';
//    print_funcs(0);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=5; j++)
        {
            // j -> inp[i][j] 로의 함수
            cin >> inp[i][j];
        }
    }
    seg_init(1, n, 0);

    int q;
    cin >> q;
    int u, a, b;
    int temp[6];
    while(q--)
    {
        cin >> u >> a >> b;
        for(int i=1; i<=5; i++)
        {
            cin >> temp[i];
        }

        query(u, a, b, temp);
    }

    return 0;
}