/*
Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.

 

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
Example 3:

Input: nums = [1], index = [0]
Output: [1]
 

Constraints:

1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i


*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct MyLinkedList{
	int val;
	struct  MyLinkedList *next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
	MyLinkedList *L;
	L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if(!L)
		return 0;
	L->next = NULL;
	return L;
}
/**获取链表中第一个索引节点的值。如果索引无效，则返回-1。**/
int myLinkedListGet(MyLinkedList* obj, int index) {
	int i=0,e;
	if(index<0)
		return -1;

	MyLinkedList *p = obj->next;
	while(p!=NULL && i<index)
	{
		i++;
		p = p->next;
	}
	if(!p)
		return -1;
	e = p->val;
	return e;
}
/*在链表的第一个元素之前添加一个val值节点。插入之后，新节点将是链表的第一个节点。*/
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList *p = obj,*s;
	s = (MyLinkedList*)malloc(sizeof(MyLinkedList));

	s->val = val;
	s->next = p->next;
	p->next = s;
}
/*将val值的节点附加到链表的最后一个元素上。*/
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	MyLinkedList *p = obj,*s;
	s = (MyLinkedList*)malloc(sizeof(MyLinkedList));

	s->val = val;
	while(p->next!=NULL)
		p = p->next;
	p->next = s;
	s->next = NULL;
}
/**在链表index之前添加一个val值节点。如果index等于链表的长度，则将节点追加到链表的末尾。如果索引大于长度，则不会插入节点。**/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	MyLinkedList *p = obj,*s;
	s = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	int j=0;
	s->val = val;
	while((p->next!=NULL) && j<index)
	{
		j++;
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
}

/** 如果索引有效，则删除链表中的第索引节点。**/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	MyLinkedList *p=obj,*q;
	int j=0;

	while((p->next!=NULL) && j<index)//找到需要删除的前一个结点
	{
		j++;
		p = p->next;
	}
	q = p->next;
	if(q)
	{
		p->next = q->next;
		free(q);
	}
}
void myLinkedListFree(MyLinkedList* obj) {
	MyLinkedList *p;
	while(obj)
	{//从头结点开始删除！第二次开始，每次释放的都是位置第一个的结点。
		p = obj->next;
		free(obj);//第一次是释放的头结点
		obj = p;
	}
}

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
	*returnSize = numsSize < indexSize ? numsSize : indexSize;
	int *target = (int *)malloc(sizeof(int) * (*returnSize));
	MyLinkedList *list = myLinkedListCreate();
	list->val = -1;
	for (int i = 0; i < *returnSize; i++) {
		myLinkedListAddAtIndex(list, index[i], nums[i]);
	}
	MyLinkedList *head = list->next;
	for (int i = 0; i < *returnSize; i++, head = head->next) {
		target[i] = head->val;
	}
	myLinkedListFree(list);
	return target;
}
