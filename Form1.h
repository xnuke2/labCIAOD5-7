#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		const static int Size = 10000000;
		const int numberofrepetitions = 1000000;
		static array<int>^ array1 = gcnew array<int>(Size+1);

		void Suboptimalbinarysearch(int key) {
			int L = 0;
			int R = Size-1;
			int i;
			int start_time = clock();
			for(int j=0;j<numberofrepetitions;j++){
				L = 0;
				R = Size-1;
				while (!(R < L)) {
					i = (L + R) / 2;
					if (key == array1[i]) {
						break;
					}
					if (key < array1[i])R = i - 1;
					else L = i + 1;
				}
			}
			int end_time = clock();
			textBoxTimeUnoptimized->Text = Convert::ToString(end_time - start_time);
			if (array1[i] == key)textBoxIndexUnoptimized->Text = Convert::ToString(i);
			else textBoxIndexUnoptimized->Text = "не найден";
		}
		void Optimalbinarysearch(int key) {
			int L = 0;
			int R = Size - 1;
			int i;
			int start_time = clock();
			for (int j = 0; j < numberofrepetitions; j++) {
				L = 0;
				R = Size - 1;
				while (R > L) {
					i = (L + R) / 2;
					if (key<=array1[i]) R = i;
					else L = i + 1;
				}
			}
			int end_time = clock();
			textBoxTimeOptimalBinarySearch->Text = Convert::ToString(end_time - start_time);
			if (array1[R] == key)textBoxIndexOptimalBinarySearch->Text = Convert::ToString(R);
			else textBoxIndexOptimalBinarySearch->Text = "не найден";
		}
	public:
		void InterpolationBinarySearch(int key) {
			long  L = 0;
			long  R = Size - 1;
			long int i=0;
			int start_time = clock();
			for (int j = 0; j < numberofrepetitions; j++) {
				L = 0;
				R = Size - 1;
				while ((array1[L] < key) && (key < array1[R])) {
					i = L + (int)(((double)(R - L) / (array1[R] - array1[L])) * (key - array1[L]));
					//i = L+ (key - array1[L]) * (R - L) / (array1[R] - array1[L]);
					if (key == array1[i]) break;
					if (key < array1[i]) R = i - 1;
					else L = i + 1;
				}

			}
			int end_time = clock();
			textBoxTimeInterpolationBinarySearch->Text= Convert::ToString(end_time - start_time);
			if (key == array1[L])i = L; else if (key == array1[R]) i = R;
			if (array1[i] == key)textBoxIndexInterpolationBinarySearch->Text = Convert::ToString(i);
			else textBoxIndexInterpolationBinarySearch->Text = "не найден";
		}

		void sequentialBinarySearch(int key) {
			int p = 0;
			int b = Size / 2;
			int start_time = clock();
			for (int j = 0; j < numberofrepetitions; j++) {
				p = 0;
				b = Size / 2;
				while (b > 0) {
					while ((p + b < Size) && (array1[p + b] <= key))p += b;
					b = b / 2;
				}
			}
			int end_time = clock();
			textBoxTimeSequentialBinarySearch->Text = Convert::ToString(end_time - start_time);
			if (array1[p] == key)textBoxIndexSequentialBinarySearch->Text = Convert::ToString(p);
			else textBoxIndexSequentialBinarySearch->Text = "не найден";

		}
		void optimized_search(int key) {
			array1[Size] = key + 1;
			int i = 0;
			int start_time = clock();
			for (int j = 0; j < numberofrepetitions/1000; j++) {
				i = 0;
				while (key > array1[i]) {
					i++;
				}
			}
			int end_time = clock();
			textBoxTimeOptimized_search->Text = Convert::ToString((end_time - start_time) * 1000);
			if (key == array1[i]) {
				textBoxIndexOptimized_search->Text = Convert::ToString(i);
			}
			else {
				textBoxIndexOptimized_search->Text = "Не найден";
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Splitter^ splitter1;
	protected:
	private: System::Windows::Forms::Splitter^ splitter2;
	private: System::Windows::Forms::Splitter^ splitter3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxTimeUnoptimized;
	private: System::Windows::Forms::TextBox^ textBoxIndexUnoptimized;
	private: System::Windows::Forms::Splitter^ splitter4;
	private: System::Windows::Forms::Splitter^ splitter5;
	private: System::Windows::Forms::Splitter^ splitter6;
	private: System::Windows::Forms::Splitter^ splitter7;
	private: System::Windows::Forms::Splitter^ splitter8;
	private: System::Windows::Forms::TextBox^ textBoxIndexOptimalBinarySearch;

	private: System::Windows::Forms::TextBox^ textBoxTimeOptimalBinarySearch;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxIndexInterpolationBinarySearch;


private: System::Windows::Forms::TextBox^ textBoxTimeInterpolationBinarySearch;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::TextBox^ textBoxIndexSequentialBinarySearch;

private: System::Windows::Forms::TextBox^ textBoxTimeSequentialBinarySearch;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::TextBox^ textBoxIndexOptimized_search;

private: System::Windows::Forms::TextBox^ textBoxTimeOptimized_search;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Splitter^ splitter9;
	private: System::Windows::Forms::Button^ buttonFind;
	private: System::Windows::Forms::Button^ buttonExit;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->splitter3 = (gcnew System::Windows::Forms::Splitter());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxTimeUnoptimized = (gcnew System::Windows::Forms::TextBox());
			this->textBoxIndexUnoptimized = (gcnew System::Windows::Forms::TextBox());
			this->splitter4 = (gcnew System::Windows::Forms::Splitter());
			this->splitter5 = (gcnew System::Windows::Forms::Splitter());
			this->splitter6 = (gcnew System::Windows::Forms::Splitter());
			this->splitter7 = (gcnew System::Windows::Forms::Splitter());
			this->splitter8 = (gcnew System::Windows::Forms::Splitter());
			this->textBoxIndexOptimalBinarySearch = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTimeOptimalBinarySearch = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxIndexInterpolationBinarySearch = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTimeInterpolationBinarySearch = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBoxIndexSequentialBinarySearch = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTimeSequentialBinarySearch = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBoxIndexOptimized_search = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTimeOptimized_search = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->splitter9 = (gcnew System::Windows::Forms::Splitter());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// splitter1
			// 
			this->splitter1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter1->Enabled = false;
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(427, 41);
			this->splitter1->TabIndex = 0;
			this->splitter1->TabStop = false;
			// 
			// splitter2
			// 
			this->splitter2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter2->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter2->Enabled = false;
			this->splitter2->Location = System::Drawing::Point(0, 41);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(427, 45);
			this->splitter2->TabIndex = 1;
			this->splitter2->TabStop = false;
			// 
			// splitter3
			// 
			this->splitter3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter3->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter3->Enabled = false;
			this->splitter3->Location = System::Drawing::Point(0, 86);
			this->splitter3->Name = L"splitter3";
			this->splitter3->Size = System::Drawing::Size(427, 72);
			this->splitter3->TabIndex = 2;
			this->splitter3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(116, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Лабораторная работа №5";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(106, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Ключ";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(186, 54);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(114, 22);
			this->numericUpDown1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(88, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(222, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Неоптимальный бинарный поиск";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Время";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(201, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Индекс";
			// 
			// textBoxTimeUnoptimized
			// 
			this->textBoxTimeUnoptimized->AllowDrop = true;
			this->textBoxTimeUnoptimized->Location = System::Drawing::Point(71, 128);
			this->textBoxTimeUnoptimized->Name = L"textBoxTimeUnoptimized";
			this->textBoxTimeUnoptimized->ReadOnly = true;
			this->textBoxTimeUnoptimized->Size = System::Drawing::Size(124, 22);
			this->textBoxTimeUnoptimized->TabIndex = 9;
			// 
			// textBoxIndexUnoptimized
			// 
			this->textBoxIndexUnoptimized->AllowDrop = true;
			this->textBoxIndexUnoptimized->Location = System::Drawing::Point(268, 128);
			this->textBoxIndexUnoptimized->Name = L"textBoxIndexUnoptimized";
			this->textBoxIndexUnoptimized->ReadOnly = true;
			this->textBoxIndexUnoptimized->Size = System::Drawing::Size(124, 22);
			this->textBoxIndexUnoptimized->TabIndex = 10;
			// 
			// splitter4
			// 
			this->splitter4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter4->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter4->Enabled = false;
			this->splitter4->Location = System::Drawing::Point(0, 158);
			this->splitter4->Name = L"splitter4";
			this->splitter4->Size = System::Drawing::Size(427, 72);
			this->splitter4->TabIndex = 11;
			this->splitter4->TabStop = false;
			// 
			// splitter5
			// 
			this->splitter5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter5->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter5->Enabled = false;
			this->splitter5->Location = System::Drawing::Point(0, 230);
			this->splitter5->Name = L"splitter5";
			this->splitter5->Size = System::Drawing::Size(427, 72);
			this->splitter5->TabIndex = 12;
			this->splitter5->TabStop = false;
			// 
			// splitter6
			// 
			this->splitter6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter6->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter6->Enabled = false;
			this->splitter6->Location = System::Drawing::Point(0, 302);
			this->splitter6->Name = L"splitter6";
			this->splitter6->Size = System::Drawing::Size(427, 72);
			this->splitter6->TabIndex = 13;
			this->splitter6->TabStop = false;
			// 
			// splitter7
			// 
			this->splitter7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter7->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter7->Enabled = false;
			this->splitter7->Location = System::Drawing::Point(0, 374);
			this->splitter7->Name = L"splitter7";
			this->splitter7->Size = System::Drawing::Size(427, 72);
			this->splitter7->TabIndex = 14;
			this->splitter7->TabStop = false;
			// 
			// splitter8
			// 
			this->splitter8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter8->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter8->Enabled = false;
			this->splitter8->Location = System::Drawing::Point(0, 446);
			this->splitter8->Name = L"splitter8";
			this->splitter8->Size = System::Drawing::Size(427, 38);
			this->splitter8->TabIndex = 15;
			this->splitter8->TabStop = false;
			// 
			// textBoxIndexOptimalBinarySearch
			// 
			this->textBoxIndexOptimalBinarySearch->AllowDrop = true;
			this->textBoxIndexOptimalBinarySearch->Location = System::Drawing::Point(268, 200);
			this->textBoxIndexOptimalBinarySearch->Name = L"textBoxIndexOptimalBinarySearch";
			this->textBoxIndexOptimalBinarySearch->ReadOnly = true;
			this->textBoxIndexOptimalBinarySearch->Size = System::Drawing::Size(124, 22);
			this->textBoxIndexOptimalBinarySearch->TabIndex = 20;
			// 
			// textBoxTimeOptimalBinarySearch
			// 
			this->textBoxTimeOptimalBinarySearch->AllowDrop = true;
			this->textBoxTimeOptimalBinarySearch->Location = System::Drawing::Point(71, 200);
			this->textBoxTimeOptimalBinarySearch->Name = L"textBoxTimeOptimalBinarySearch";
			this->textBoxTimeOptimalBinarySearch->ReadOnly = true;
			this->textBoxTimeOptimalBinarySearch->Size = System::Drawing::Size(124, 22);
			this->textBoxTimeOptimalBinarySearch->TabIndex = 19;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(201, 200);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 16);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Индекс";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 200);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 16);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Время";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(88, 172);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(206, 16);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Oптимальный бинарный поиск";
			// 
			// textBoxIndexInterpolationBinarySearch
			// 
			this->textBoxIndexInterpolationBinarySearch->AllowDrop = true;
			this->textBoxIndexInterpolationBinarySearch->Location = System::Drawing::Point(268, 272);
			this->textBoxIndexInterpolationBinarySearch->Name = L"textBoxIndexInterpolationBinarySearch";
			this->textBoxIndexInterpolationBinarySearch->ReadOnly = true;
			this->textBoxIndexInterpolationBinarySearch->Size = System::Drawing::Size(124, 22);
			this->textBoxIndexInterpolationBinarySearch->TabIndex = 25;
			// 
			// textBoxTimeInterpolationBinarySearch
			// 
			this->textBoxTimeInterpolationBinarySearch->AllowDrop = true;
			this->textBoxTimeInterpolationBinarySearch->Location = System::Drawing::Point(71, 272);
			this->textBoxTimeInterpolationBinarySearch->Name = L"textBoxTimeInterpolationBinarySearch";
			this->textBoxTimeInterpolationBinarySearch->ReadOnly = true;
			this->textBoxTimeInterpolationBinarySearch->Size = System::Drawing::Size(124, 22);
			this->textBoxTimeInterpolationBinarySearch->TabIndex = 24;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(201, 272);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 16);
			this->label9->TabIndex = 23;
			this->label9->Text = L"Индекс";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(12, 272);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 16);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Время";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(88, 244);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(245, 16);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Интерполяционный бинарный поиск";
			// 
			// textBoxIndexSequentialBinarySearch
			// 
			this->textBoxIndexSequentialBinarySearch->AllowDrop = true;
			this->textBoxIndexSequentialBinarySearch->Location = System::Drawing::Point(268, 344);
			this->textBoxIndexSequentialBinarySearch->Name = L"textBoxIndexSequentialBinarySearch";
			this->textBoxIndexSequentialBinarySearch->ReadOnly = true;
			this->textBoxIndexSequentialBinarySearch->Size = System::Drawing::Size(124, 22);
			this->textBoxIndexSequentialBinarySearch->TabIndex = 30;
			// 
			// textBoxTimeSequentialBinarySearch
			// 
			this->textBoxTimeSequentialBinarySearch->AllowDrop = true;
			this->textBoxTimeSequentialBinarySearch->Location = System::Drawing::Point(71, 344);
			this->textBoxTimeSequentialBinarySearch->Name = L"textBoxTimeSequentialBinarySearch";
			this->textBoxTimeSequentialBinarySearch->ReadOnly = true;
			this->textBoxTimeSequentialBinarySearch->Size = System::Drawing::Size(124, 22);
			this->textBoxTimeSequentialBinarySearch->TabIndex = 29;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(201, 344);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(55, 16);
			this->label12->TabIndex = 28;
			this->label12->Text = L"Индекс";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(12, 344);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(48, 16);
			this->label13->TabIndex = 27;
			this->label13->Text = L"Время";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(88, 316);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(254, 16);
			this->label14->TabIndex = 26;
			this->label14->Text = L"\"Последовательный\" бинарный поиск";
			// 
			// textBoxIndexOptimized_search
			// 
			this->textBoxIndexOptimized_search->AllowDrop = true;
			this->textBoxIndexOptimized_search->Location = System::Drawing::Point(268, 416);
			this->textBoxIndexOptimized_search->Name = L"textBoxIndexOptimized_search";
			this->textBoxIndexOptimized_search->ReadOnly = true;
			this->textBoxIndexOptimized_search->Size = System::Drawing::Size(124, 22);
			this->textBoxIndexOptimized_search->TabIndex = 35;
			this->textBoxIndexOptimized_search->TextChanged += gcnew System::EventHandler(this, &Form1::textBox9_TextChanged);
			// 
			// textBoxTimeOptimized_search
			// 
			this->textBoxTimeOptimized_search->AllowDrop = true;
			this->textBoxTimeOptimized_search->Location = System::Drawing::Point(71, 416);
			this->textBoxTimeOptimized_search->Name = L"textBoxTimeOptimized_search";
			this->textBoxTimeOptimized_search->ReadOnly = true;
			this->textBoxTimeOptimized_search->Size = System::Drawing::Size(124, 22);
			this->textBoxTimeOptimized_search->TabIndex = 34;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(201, 416);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(55, 16);
			this->label15->TabIndex = 33;
			this->label15->Text = L"Индекс";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(12, 416);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(48, 16);
			this->label16->TabIndex = 32;
			this->label16->Text = L"Время";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(12, 386);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(352, 16);
			this->label17->TabIndex = 31;
			this->label17->Text = L"Последовательный поиск в упорядоченном массиве";
			// 
			// splitter9
			// 
			this->splitter9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitter9->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter9->Enabled = false;
			this->splitter9->Location = System::Drawing::Point(0, 484);
			this->splitter9->Name = L"splitter9";
			this->splitter9->Size = System::Drawing::Size(427, 38);
			this->splitter9->TabIndex = 36;
			this->splitter9->TabStop = false;
			// 
			// buttonFind
			// 
			this->buttonFind->Location = System::Drawing::Point(141, 452);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(121, 25);
			this->buttonFind->TabIndex = 37;
			this->buttonFind->Text = L"Найти";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &Form1::buttonFind_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(294, 490);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(121, 25);
			this->buttonExit->TabIndex = 38;
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form1::buttonExit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(427, 522);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->splitter9);
			this->Controls->Add(this->textBoxIndexOptimized_search);
			this->Controls->Add(this->textBoxTimeOptimized_search);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBoxIndexSequentialBinarySearch);
			this->Controls->Add(this->textBoxTimeSequentialBinarySearch);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBoxIndexInterpolationBinarySearch);
			this->Controls->Add(this->textBoxTimeInterpolationBinarySearch);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBoxIndexOptimalBinarySearch);
			this->Controls->Add(this->textBoxTimeOptimalBinarySearch);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->splitter8);
			this->Controls->Add(this->splitter7);
			this->Controls->Add(this->splitter6);
			this->Controls->Add(this->splitter5);
			this->Controls->Add(this->splitter4);
			this->Controls->Add(this->textBoxIndexUnoptimized);
			this->Controls->Add(this->textBoxTimeUnoptimized);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->splitter3);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->splitter1);
			this->Name = L"Form1";
			this->Text = L"ЛР5-7 Хмыренков";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	Random^ rnd = gcnew Random();
	array1[0] = rnd->Next(0, 5);
	for (int i = 1; i < Size; i++) {
		array1[i] = array1[i - 1] + rnd->Next(1, 5);
	}
}
private: System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e) {
	Suboptimalbinarysearch(Convert::ToInt64(numericUpDown1->Value));
	Optimalbinarysearch(Convert::ToInt64(numericUpDown1->Value));
	InterpolationBinarySearch(Convert::ToInt64(numericUpDown1->Value));
	sequentialBinarySearch(Convert::ToInt64(numericUpDown1->Value));
	optimized_search(Convert::ToInt64(numericUpDown1->Value));
}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
