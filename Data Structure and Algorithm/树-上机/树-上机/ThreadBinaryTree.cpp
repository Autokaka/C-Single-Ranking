#include "ThreadBinaryTree.h"

ThreadBinaryTree::ThreadBinaryTree(treemode mode) {
	treeMode = mode;
	//����ͷ���
	threadTree = Empty(threadTree);
}
ThreadBinaryTree::ThreadBinaryTree(treemode mode, eletype order[], int len) {
	treeMode = mode;
	//����ͷ���
	threadTree = Empty(threadTree);
	if (len == 0) cout << "Can't initialize object ThreadBinaryTree: array length is 0.\n";
	else {
		//��ʼ����������
		head()->lchild = createTreeNode(order[0], NULL, LINK, NULL, LINK);
		treeStatus.push(head()->lchild);
		int i = 1;
		while (i < len) {
			if (treeStatus.front()->lchild == NULL) treeStatus.front()->lchild = createTreeNode(order[i++], NULL, LINK, NULL, LINK);
			treeStatus.push(treeStatus.front()->lchild);
			if (i >= len) break;
			if (treeStatus.front()->rchild == NULL) treeStatus.front()->rchild = createTreeNode(order[i++], NULL, LINK, NULL, LINK);
			treeStatus.push(treeStatus.front()->rchild);
			if (i >= len) break;
			treeStatus.pop();
		}
		buildThread(head()->lchild, head(), head()->lchild);
		//�����һ�������Һ���ָ��ͷ���
		fetchLChildsMostRight(head())->rchild = head();
	}
}

ThreadBinaryTree::treenode ThreadBinaryTree::Empty(treenode tgt)  {
	isThreadBuilt = false;
	return (createTreeNode(0, NULL, LINK, tgt, LINK));
}
bool ThreadBinaryTree::isEmpty(treenode tgt) {
	return (tgt == NULL);
}

ThreadBinaryTree::treenode ThreadBinaryTree::createTreeNode(eletype val, treenode lchild, tag ltag, treenode rchild, tag rtag) {
	treenode add = new celltype;
	add->data = val;
	add->lchild = lchild;
	add->ltag = ltag;
	add->rchild = rchild;
	add->rtag = rtag;
	return add;
}
ThreadBinaryTree::treenode ThreadBinaryTree::head() {
	return threadTree;
}
ThreadBinaryTree::treenode ThreadBinaryTree::first() {
	if (isEmpty(head())) {
		cout << "Can't execute first: Object ThreadBinaryTree is not initialized.\n";
		return NULL;
	}
	return threadTree->lchild;
}
ThreadBinaryTree::eletype ThreadBinaryTree::data(treenode tgt) {
	return tgt->data;
}
ThreadBinaryTree::treenode ThreadBinaryTree::leftChild(treenode parent) {
	if (!isThreadBuilt) {
		cout << "Can't return leftChild: Thread is not initialized." << endl;
		return NULL;
	};
	return parent->lchild;
}
ThreadBinaryTree::treenode ThreadBinaryTree::rightChild(treenode parent) {
	if (!isThreadBuilt) {
		cout << "Can't return rightChild: Thread is not initialized." << endl;
		return NULL;
	};
	return parent->rchild;
}

void ThreadBinaryTree::leftInsert(treenode tgt, treenode add) {
	if (!isThreadBuilt) {
		cout << "Can't execute leftInsert: Thread is not built." << endl;
		return;
	}
	switch (treeMode) {
	default:
		cout << "Can't execute leftInsert: TreeMode is not correct." << endl;
		break;
	case PRE:

		break;
	case IN:
		add->rchild = tgt;
		add->rtag = THREAD;
		add->lchild = tgt->lchild;
		add->ltag = tgt->ltag;
		tgt->lchild = add;
		if (LINK == tgt->ltag) fetchLChildsMostRight(add)->rchild = add;
		tgt->ltag = LINK;
		break;
	case POST:

		break;
	}
}
void ThreadBinaryTree::rightInsert(treenode tgt, treenode add) {
	if (!isThreadBuilt) {
		cout << "Can't execute rightInsert: Thread is not built." << endl;
		return;
	}
	switch (treeMode) {
	default:
		cout << "Can't execute rightInsert: TreeMode is not correct." << endl;
		break;
	case PRE:
		/*
		treenode originalRChild = tgt->rchild;
		tgt->rchild = add;
		//add�������ӵ�tgt������ӵ����ҽ��
		if (tgt->ltag == LINK) {
			treenode lChildsMostRight = fetchLChildsMostRight(tgt);
			lChildsMostRight->rchild = add;
			add->lchild = lChildsMostRight;
		}
		else add->lchild = tgt;
		add->ltag = THREAD;
		//add���Һ���ά��
		add->rchild = originalRChild;
		add->rtag = tgt->rtag;
		if (originalRChild->ltag == THREAD) originalRChild->lchild = add;
		tgt->rtag = LINK;
		*/
		break;
	case IN:
		add->lchild = tgt;
		add->ltag = THREAD;
		add->rchild = tgt->rchild;
		add->rtag = tgt->rtag;
		tgt->rchild = add;
		//�ҵ��Һ��ӵ�����ڵ�
		if (tgt->rtag == LINK) fetchRChildsMostLeft(add)->lchild = add;
		tgt->rtag = LINK;
		break;
	case POST:

		break;
	}
}
void ThreadBinaryTree::buildThread(treenode now, treenode pre, treenode next) {
	isThreadBuilt = true;
	switch (treeMode) {
	default:
		cout << "������ģʽ����, �޷���ȡ��һ���..." << endl;
		break;
	case PRE://��������������
		//�����м�����
		if (now->ltag == LINK && now->lchild == NULL) {
			now->ltag = THREAD;
			now->lchild = pre;
		}
		if (now->rtag == LINK && now->rchild == NULL) {
			now->rtag = THREAD;
			now->rchild = next;
		}
		//�����������
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild == NULL) buildThread(now->lchild, now, next);
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild != NULL) buildThread(now->lchild, now, now->rchild);
		//�����Ҳ�����
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild == NULL) buildThread(now->rchild, now, next);
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild != NULL) buildThread(now->rchild, now->lchild, next);
		break;
	case IN://��������������
		//�����ж���, ������������
		if (now->lchild != NULL) buildThread(now->lchild, pre, now);
		//����Ϊ��, ��������
		else {
			now->ltag = THREAD;
			now->lchild = pre;
			cout << "** ���Խӿ�(���ޱ�Ҫ����ɾ��) **" << endl;
			cout << "���������Ľ��: " << now->data << endl;
			cout << "��ǰ���������: " << pre->data << endl << endl;
		}
		//�Һ����ж���, ������������
		if (now->rchild != NULL) buildThread(now->rchild, now, next);
		//�Һ���Ϊ��, ��������
		else {
			now->rtag = THREAD;
			now->rchild = next;
			cout << "** ���Խӿ�(���ޱ�Ҫ����ɾ��) **" << endl;
			cout << "���������Ľ��: " << now->data << endl;
			cout << "�����������: " << next->data << endl << endl;
		}
		break;
	case POST://��������������
		//�����������
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild == NULL) buildThread(now->lchild, pre, now);
		if (now->ltag == LINK && now->lchild != NULL && now->rtag == LINK && now->rchild != NULL) buildThread(now->lchild, pre, now->rchild);
		//�����Ҳ�����
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild == NULL) buildThread(now->rchild, pre, now);
		if (now->rtag == LINK && now->rchild != NULL && now->ltag == LINK && now->lchild != NULL) buildThread(now->rchild, now->lchild, now);
		//�����м�����
		if (now->ltag == LINK && now->lchild == NULL) {
			now->ltag = THREAD;
			now->lchild = pre;
		}
		if (now->rtag == LINK && now->rchild == NULL) {
			now->rtag = THREAD;
			now->rchild = next;
		}
		break;
	}
}
ThreadBinaryTree::treenode ThreadBinaryTree::fetchRChildsMostLeft(treenode now) {
	if (!isThreadBuilt) {
		cout << "Can't fetchRChildsMostLeft: Thread is not built." << endl;
		return NULL;
	}
	treenode srch = now->rchild;
	while (srch->ltag == LINK && srch->lchild != NULL) srch = srch->lchild;
	return srch;
}
ThreadBinaryTree::treenode ThreadBinaryTree::fetchLChildsMostRight(treenode now) {
	if (!isThreadBuilt) {
		cout << "Can't fetchLChildsMostRight: Thread is not built." << endl;
		return NULL;
	}
	treenode srch = now->lchild;
	while (srch->rtag == LINK && srch->rchild != NULL) srch = srch->rchild;
	return srch;
}

ostream& operator<<(ostream& out, const ThreadBinaryTree& tgt) {
	//����Ƿ�����������
	if (!tgt.isThreadBuilt) {
		out << "Can't display inner structure of this thread binary tree: Thread is not built.\n";
		return out;
	}
	ThreadBinaryTree::treenode srch;
	//�жϸ�������ڴ洢������������
	switch (tgt.treeMode)
	{
	default:
		break;
	case tgt.PRE://��������������
		break;
	case tgt.IN://��������������
		//�ҵ�������
		srch = tgt.threadTree->lchild;
		while (srch->ltag == tgt.LINK) srch = srch->lchild;
		//һ��һ��������
		while (srch != tgt.threadTree) {
			out << srch->data << " ";
			if (srch->rtag == tgt.THREAD) srch = srch->rchild;
			else {
				srch = srch->rchild;
				while (srch->ltag == tgt.LINK) srch = srch->lchild;
			}
		}
		break;
	case tgt.POST://��������������
		break;
	}
	return out;
}