typedef int DATA;

typedef struct {
    int start;
    int end;
    int max;
    DATA * v;
} queue;

typedef queue * qup;

qup createQueue (int size);
void insertInQueue(qup Q, DATA);
int emptyQueue(qup Q);
int removeFromQueue(qup Q);
DATA firstInQueue (qup Q);
void resizeQueue (qup Q, int newSize);