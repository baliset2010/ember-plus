音声パラメータ [1-512ch]
	MIC(id:01)
		slot No.(INTEGER)
			1-14
		カード内 ch No.(INTEGER)
			1-64
		Head Room(INTEGER?)
			0-3
		HAゲイン(INTEGER?)
			0-255
		PA48 or SRC?(INTEGER?)
			0-255
	LINE IN(id:02)
		slot No.(INTEGER)
			1-14
		カード内 ch No.(INTEGER)
			1-64
		Head Room(INTEGER?)
			0-3
		アナログ・リファレンス・レベル(INTEGER?)
			0-255
	LINE OUT(id:03)
		slot No.(INTEGER)
			1-14
		アナログ・リファレンス・レベル(INTEGER?)
			0-255
	AES INPUT(id:04)
		slot No.(INTEGER)
			1-14
		デジタル・リファレンス・レベル(0固定)
	AES OUTPUT(id:05)
		slot No.(INTEGER)
			1-14
		デジタル・リファレンス・レベル(0固定)
	GPIO(id:06)
		slot No.(INTEGER)
			1-14
		カード内 ch No.(INTEGER)
			1-64
		GPI設定[1-24]
			Sense(ENUM)
				Level
				Toggle
				ALT SEL A
				ALT SEL A <-
				ALT SEL B
				ALT SEL B <-
			Status(BOOL)
				OFF
				ON
			Resume(BOOL)
				OFF
				ON
		GPO設定[1-16]
			Control Source
				Network
				GPI 1-24 の折返し
		GPO出力[1-16]
			端子番号(INTEGER)
				0-15
			出力(BOOL)
				OFF
				ON
	SDI IN/3G SDI IN(7) - 未サポート？
	MADI/Dante/12GSDI - 未サポート？
	Network MADI - 未サポート？
	AoIP Card - 未サポート？
	


GPI[1-512ch]
	slot No.(INTEGER)
		1-14
	カード内 ch No.(INTEGER)
		1-64
	GPO設定[1-16] は音声パラメータのものと同じ
	GPO出力[1-16] は音声パラメータのものと同じ
	GPI[1-24]
		変化回数(INTEGER)
			0-15
		入力(BOOL)
			OFF
			ON


