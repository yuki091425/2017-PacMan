#ifndef	COLLISION_H
#define COLLISION_H

/*�L�����N�^�[��x.y.scale������̂Ŗ��O��ς���STATE�ɂ��Ă�����*/
struct Circle
{
	float x, y;		/*x,y�̒��S���W*/
	float r;		/*�~�̔��a*/
};

//�\���̂�����Ă���ŋ�`���m�̓����蔻������B
struct RectangleCC
{
	float x;
	float y;
	float x2;
	float y2;
};

bool collisionKK(RectangleCC a, RectangleCC b);

#endif