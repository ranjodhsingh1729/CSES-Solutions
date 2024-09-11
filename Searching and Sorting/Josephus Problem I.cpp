#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef struct {
    int value;
    void *prev;
    void *next;
} node;



int main() {
    int n;
    cin >> n;

    node *start = (node *) malloc(sizeof(node));
    
    start->value = 1;
    node *tmp = start, *prev = start;
    for (int i = 1+1; i <= n; i++) {
        tmp = (node *) malloc(sizeof(node));

        tmp->value = i;
        tmp->prev = prev;
        prev->next = tmp;

        prev = tmp;
    }
    start->prev = tmp;
    tmp->next = start;


    node *zmp;
    tmp = start;
    while (tmp != tmp->next) {
        tmp = (node *) (tmp->next);        

        ((node *) tmp->prev)->next = (node *) tmp->next;
        ((node *) tmp->next)->prev = (node *) tmp->prev;

        cout << tmp->value << ' ';

        zmp = tmp;
        tmp = (node *) (tmp->next);        
        free(zmp);
    }

    cout << tmp->value << '\n';
    free(tmp);

    return 0;
}