#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LineareAlgebra/include/Vector3f.h"
#include "../LineareAlgebra/include/Physics.h"
#include "../LineareAlgebra/include/Objects.h"
#include "../SDL2/include/SDL_stdinc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Physics_2Dcollision__true_collision_test)
		{
			// TODO: Your test code here

			// Shape 1
			Vector3f vs1 = Vector3f(0, 0, 0);
			Vector3f vs2 = Vector3f(1, 0, 0);
			Vector3f vs3 = Vector3f(0, 1, 0);
			Vector3f vs4 = Vector3f(1, 1, 0);

			Matrix3f sm1;
			sm1.AddVector(vs1, vs2, vs3, vs4);
			Shape shape1;
			shape1.addMatix(sm1);

			// Shape 2
			Vector3f vs11(0.5, 0.5, 0);
			Vector3f vs21(1.5, 0.5, 0);
			Vector3f vs31(0.5, 1.5, 0);
			Vector3f vs41(1.5, 1.5, 0);

			Matrix3f ssm1;
			ssm1.AddVector(vs11, vs21, vs31, vs41);
			Shape shape2;
			shape2.addMatix(ssm1);


			Assert::AreEqual(true, Physics::calculateIntersection(shape1, shape2));
			//Assert::AreEqual(true, true);
		}
		TEST_METHOD(Physics_2Dcollision__false_collision_test)
		{
			// TODO: Your test code here

			// Shape 1
			Vector3f vs1 = Vector3f(0, 0, 0);
			Vector3f vs2 = Vector3f(1, 0, 0);
			Vector3f vs3 = Vector3f(1, 1, 0);
			Vector3f vs4 = Vector3f(0, 1, 0);

			Matrix3f sm1;
			sm1.AddVector(vs1, vs2, vs3, vs4);
			Shape shape1;
			shape1.addMatix(sm1);

			// Shape 2
			Vector3f vs11(2, 2, 0);
			Vector3f vs21(3, 2, 0);
			Vector3f vs31(3, 3, 0);
			Vector3f vs41(2, 3, 0);

			Matrix3f ssm1;
			ssm1.AddVector(vs11, vs21, vs31, vs41);
			Shape shape2;
			shape2.addMatix(ssm1);


			Assert::AreEqual(false, Physics::calculateIntersection(shape1, shape2));
			//Assert::AreEqual(true, true);
		}

		TEST_METHOD(Physics_3Dcollision__true_collision_test)
		{
			// Shape 1

			Shape cube1 = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
			Shape cube2 = Shape(Objects::cube(Vector3f{ 1,1,1 }), Vector3f{ 1,1,1 });


			Assert::AreEqual(true, Physics::calculateIntersection(cube1, cube2));
		}
		TEST_METHOD(Physics_3Dcollision__false_collision_test)
		{
			// Shape 1

			Shape cube1 = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
			Shape cube2 = Shape(Objects::cube(Vector3f{ 1.1f,1.1f,1.1f }), Vector3f{ 1.1f,1.1f,1.1f });


			Assert::AreEqual(false, Physics::calculateIntersection(cube1, cube2));
		}

		TEST_METHOD(Calculate_true_InProduct)
		{
			Vector3f v1 = Vector3f(4, 5, 6);
			Vector3f v2 = Vector3f(1, 2, 3);
			auto x = v1 * v2;
			Assert::AreEqual(32.f, x);
		}
		TEST_METHOD(Calculate_false_InProduct)
		{
			Vector3f v1 = Vector3f(7, 8, 2);
			Vector3f v2 = Vector3f(4, 1, 9);
			auto x = v1 * v2;
			Assert::AreNotEqual(53.f, x);
		}
		TEST_METHOD(Shape_true_scale)
		{
			Shape cube1 = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
			cube1.scale(Vector3f(2, 2, 2));

			auto v = cube1.projections()[0].getMatrix()[0];
			auto x = v[0];
			auto y = v[1];
			auto z = v[2];
			Assert::AreEqual(x, -1.0f);
			Assert::AreEqual(y, -1.0f);
			Assert::AreEqual(z, 1.0f);
		}
		TEST_METHOD(Shape_false_scale)
		{
			Shape cube1 = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
			cube1.scale(Vector3f(2, 2, 2));

			auto v = cube1.projections()[0].getMatrix()[0];
			auto x = v[0];
			auto y = v[1];
			auto z = v[2];
			Assert::AreNotEqual(x, 1.0f);
			Assert::AreNotEqual(y, 1.0f);
			Assert::AreNotEqual(z, -1.0f);
		}
		TEST_METHOD(Physics_true_calculateOutProduct)
		{
			Vector3f v1 = Vector3f(1, 0, 0);
			Vector3f v2 = Vector3f(0, 1, 0);

			Vector3f v3 = Physics::calculateOutProduct(v1, v2);

			auto x = v3[0];
			auto y = v3[1];
			auto z = v3[2];

			Assert::AreEqual(x, 0.f);
			Assert::AreEqual(y, 0.f);
			Assert::AreEqual(z, 1.f);
		}

		TEST_METHOD(Physics_false_calculateOutProduct)
		{
			Vector3f v1 = Vector3f(1, 0, 0);
			Vector3f v2 = Vector3f(1, 0, 0);

			Vector3f v3 = Physics::calculateOutProduct(v1, v2);

			auto x = v3[0];
			auto y = v3[1];
			auto z = v3[2];

			Assert::AreNotEqual(x, 1.f);
			Assert::AreNotEqual(y, 1.f);
			Assert::AreNotEqual(z, 1.f);
		}
		TEST_METHOD(Shape_true_translate)
		{
			Shape shape = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
			shape.translate(Vector3f(1, 3, 18));
			auto v3 = shape.getPosition();
			auto x = v3[0];
			auto y = v3[1];
			auto z = v3[2];
			Assert::AreEqual(1.f, x);
			Assert::AreEqual(3.f, y);
			Assert::AreEqual(18.f, z);
		}
		TEST_METHOD(Shape_false_translate)
		{
			Shape shape = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
			shape.translate(Vector3f(2, 3, 18));
			auto v3 = shape.getPosition();
			auto x = v3[0];
			auto y = v3[1];
			auto z = v3[2];
			Assert::AreNotEqual(1.f, x);
			Assert::AreNotEqual(1.f, y);
			Assert::AreNotEqual(1.f, z);
		}
		TEST_METHOD(Physics_true_convertToRadials)
		{
			auto r = Physics::convertToRadials(180);

			Assert::AreEqual((float)M_PI, r);
		}
		TEST_METHOD(Physics_false_convertToRadials)
		{
			auto r = Physics::convertToRadials(180);

			Assert::AreNotEqual(2.15f, r);
		}
		TEST_METHOD(Physics_true_convertTodegrees)
		{
			auto r = Physics::convertToDegrees((float)M_PI);

			Assert::AreEqual(180.f, r);
		}
		TEST_METHOD(Physics_false_convertTodegrees)
		{
			auto r = Physics::convertToDegrees(16);

			Assert::AreNotEqual(0.0215f, r);
		}
		TEST_METHOD(Physics_true_calculateDirectionVector)
		{
			Vector3f v1 = Vector3f(4,6,4);
			Vector3f v2 = Vector3f(5,6,2);

			Vector3f v3 = Physics::calculateDirectionVector(v1, v2);
			auto x = v3[0];
			auto y = v3[1];
			auto z = v3[2];

			Assert::AreEqual(x , -1.f);
			Assert::AreEqual(y , 0.f);
			Assert::AreEqual(z , 2.f);
		}
		TEST_METHOD(Physics_false_calculateDirectionVector)
		{
			Vector3f v1 = Vector3f(4, 6, 4);
			Vector3f v2 = Vector3f(5, 6, 2);

			Vector3f v3 = Physics::calculateDirectionVector(v1, v2);
			auto x = v3[0];
			auto y = v3[1];
			auto z = v3[2];

			Assert::AreNotEqual(x, -2.f);
			Assert::AreNotEqual(y, 5.f);
			Assert::AreNotEqual(z, 21.f);
		}
	};
}