#include "_CLASS_H_.h"
////////////////////////////����� �����////////////////////////
class Enemy :public Entity {
public:
	int direction;//����������� �������� �����
	Enemy(Image &image, float X, float Y, int W, int H, std::string Name);//:Entity(image, X, Y, W, H, Name);
	void checkCollisionWithMap(float Dx, float Dy);//�-��� �������� ������������ � ������
	void update(float time);
};//����� Enemy ������
