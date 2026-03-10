#define IM_PI                   3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))

void VectorAnglesRadar(FVector & forward, FVector & angles) {
	if (forward.X == 0.f && forward.Y == 0.f) {
		angles.X = forward.Z > 0.f ? -90.f : 90.f;
		angles.Y = 0.f;
	} else {
		angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
		angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
	}
	angles.Z = 0.f;
}

FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, FVector Size, bool & outbuff) {
	bool flag = false;
	double num = (double)Yaw;
	double num2 = num * 0.017453292519943295;
	float num3 = (float)std::cosf(num2);
	float num4 = (float)std::sinf(num2);
	float num5 = Origin.X - LocalOrigin.X;
	float num6 = Origin.Y - LocalOrigin.Y;
	FVector Xector;
	Xector.X = (num6 * num3 - num5 * num4) / 150.f;
	Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
    FVector Xector2;
	Xector2.X = Xector.X + PosX + Size.X / 2.f;
	Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
	bool flag2 = Xector2.X > PosX + Size.X;
	if (flag2) {
		Xector2.X = PosX + Size.X;
	} else {
		bool flag3 = Xector2.X < PosX;
		if (flag3) {
			Xector2.X = PosX;
		}
	}
	bool flag4 = Xector2.Y > PosY + Size.Y;
	if (flag4) {
		Xector2.Y = PosY + Size.Y;
	} else {
		bool flag5 = Xector2.Y < PosY;
		if (flag5) {
			Xector2.Y = PosY;
		}
	}
	bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
	if (flag6) {
		flag = true;
	}
	outbuff = flag;
	return Xector2;
}

void RotateTriangle(std::array<FVector, 3> & points, float rotation) {
	const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
	for (auto & point : points) {
		point = point - points_center;
		const auto temp_x = point.X;
		const auto temp_y = point.Y;
		const auto theta = DEG2RAD(rotation);
		const auto c = cosf(theta);
		const auto s = sinf(theta);
		point.X = temp_x * c - temp_y * s;
		point.Y = temp_x * s + temp_y * c;
		point = point + points_center;
	}
}
