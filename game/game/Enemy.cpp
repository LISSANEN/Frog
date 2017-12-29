#include "_CLASS_H_.h"
#include "map.h"
#include "Enemy.h"


Enemy::Enemy(Image &image, float X, float Y, int W, int H, std::string Name):Entity(image, X, Y, W, H, Name)
{	
if (name == "EasyEnemy"){
		//������ ������� ���� ������������� ���
		//������ ������ ������. IntRect � ��� ���������� �����
		sprite.setTextureRect(IntRect(0, 0, w, h));
		direction = rand() % (5); //����������� �������� ����� ����� ��������� �������
			//����� ��������� ��������� �����
			speed = 0.05;//���� ��������.���� ������ ������ ���������
			dx = speed;
		}
}

void Enemy::checkCollisionWithMap(float Dx, float Dy)//�-��� �������� ������������ � ������
	{
	for (int i = y / 50; i < (y + h) / 50; i++)//���������� �� ��������� �����
		for (int j = x / 50; j<(x + w) / 50; j++)
		{
			if (TileMap[i][j] == '0')//���� ������� - ������ �����
			{
				if (Dy > 0) {
					y = i * 50 - h;  dy = -0.1; 
					direction = rand() % (3); //����������� �������� �����
						}//�� Y 
				if (Dy < 0) {
					y = i * 50 + 50; dy = 0.1; 
					direction = rand() % (3);//����������� �������� ����� 
						}//������������ � �������� ������ 
				if (Dx > 0) {
					x = j * 50 - w; dx = -0.1; 
						direction = rand() % (3);//����������� �������� ����� 
						}//� ������ ����� �����
				if (Dx < 0) {
					x = j * 50 + 50; dx = 0.1; 
						direction = rand() % (3); //����������� �������� �����
						}// � ����� ����� �����
				}
			}
	}

	void Enemy::update(float time)
	{
		if (name == "EasyEnemy"){//��� ��������� � ����� ������ ������ ����� �����

		if (life) {//���������, ��� �� �����
		switch (direction)//�������� ��������� �������� � ����������� �� ���������
		{
		case 0:{//��������� ���� ������
		dx = speed;
		CurrentFrame += 0.000001*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(58 * int(CurrentFrame), 54, 58, 54));
		break;
		}
		case 1:{//��������� ���� �����
		dx = -speed;
		CurrentFrame +=  0.000001*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(58 * int(CurrentFrame), 0, 58, 54));
		break;
		}
		case 2:{//���� �����
		dy = -speed;
		CurrentFrame += 0.000001*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(0 * int(CurrentFrame), 0, 58, 54));
		break;
		}
		case 3:{//���� ����
		dy = speed;
		CurrentFrame +=  0.000001*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(0 * int(CurrentFrame),54, 58, 54));
		break;
		}
		}

		x += dx*time; //�������� �� �X�
		checkCollisionWithMap(dx, 0);//������������ ������������ �� �

		y += dy*time; //�������� �� �Y�
		checkCollisionWithMap(0, dy);//������������ ������������ �� Y

		sprite.setPosition(x, y); //������ � ������� (x, y).

		if (health <= 0){ life = false; }//���� ������ ������ 0, ���� ����� 0, �� �������
		}
		//if (playerScoreSting = 50)
		}
	};

