#pragma once
#include <string>
#include "Resultado.h"
#include "pch.h"
#include <tuple>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
namespace Prueba1 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;
    using namespace System::Reflection;
    using namespace System::IO;
    /// <summary>
    /// Resumen de Resultado
    /// </summary>
    public ref class Resultado : public System::Windows::Forms::Form
    {
        float pr_inv, Pm = 450, Im = 10.7, Vm = 42.06, Isc = 11.36, Voc = 50.43, prpan = 170, npanel = 0.9, kt = 0.7, areapanel = 2.20, anterior = 0, ant=0; //TSM450W Beyond Sun
        private: System::Windows::Forms::Label^ label2;
        private: System::Windows::Forms::Label^ label3;
        private: System::Windows::Forms::RichTextBox^ richTextBox1;
        private: System::Windows::Forms::RichTextBox^ richTextBox2;
        private: System::Windows::Forms::RichTextBox^ richTextBox3;
        private: System::Windows::Forms::RichTextBox^ richTextBox4;
        private: System::Windows::Forms::RichTextBox^ richTextBox5;
        private: System::Windows::Forms::RichTextBox^ richTextBox6;
        private: System::Windows::Forms::RichTextBox^ richTextBox7;
        private: System::Windows::Forms::RichTextBox^ richTextBox8;
        private: System::Windows::Forms::RichTextBox^ richTextBox9;
        private: System::Windows::Forms::RichTextBox^ richTextBox10;
        private: System::Windows::Forms::RichTextBox^ richTextBox11;
        private: System::Windows::Forms::RichTextBox^ richTextBox12;
        private: System::Windows::Forms::RichTextBox^ richTextBox13;
        private: System::Windows::Forms::RichTextBox^ rtb_1;
        private: System::Windows::Forms::RichTextBox^ rtb_2;
        private: System::Windows::Forms::RichTextBox^ rtb_4;
        private: System::Windows::Forms::RichTextBox^ rtb_3;
        private: System::Windows::Forms::RichTextBox^ rtb_8;
        private: System::Windows::Forms::RichTextBox^ rtb_7;
        private: System::Windows::Forms::RichTextBox^ rtb_6;
        private: System::Windows::Forms::RichTextBox^ rtb_5;
        private: System::Windows::Forms::RichTextBox^ rtb_12;
        private: System::Windows::Forms::RichTextBox^ rtb_11;
        private: System::Windows::Forms::RichTextBox^ rtb_10;
        private: System::Windows::Forms::RichTextBox^ rtb_9;
        private: System::Windows::Forms::RichTextBox^ rtb_13;
        private: System::Windows::Forms::RichTextBox^ richTextBox14;
        private: System::Windows::Forms::RichTextBox^ richTextBox15;
        private: System::Windows::Forms::RichTextBox^ rtb_26;
        private: System::Windows::Forms::RichTextBox^ rtb_25;
        private: System::Windows::Forms::RichTextBox^ rtb_24;
        private: System::Windows::Forms::RichTextBox^ rtb_23;
        private: System::Windows::Forms::RichTextBox^ rtb_22;
        private: System::Windows::Forms::RichTextBox^ rtb_21;
        private: System::Windows::Forms::RichTextBox^ rtb_20;
        private: System::Windows::Forms::RichTextBox^ rtb_19;
        private: System::Windows::Forms::RichTextBox^ rtb_18;
        private: System::Windows::Forms::RichTextBox^ rtb_17;
        private: System::Windows::Forms::RichTextBox^ rtb_16;
        private: System::Windows::Forms::RichTextBox^ rtb_15;
        private: System::Windows::Forms::RichTextBox^ rtb_14;
        private: System::Windows::Forms::RichTextBox^ richTextBox16;
        private: System::Windows::Forms::RichTextBox^ rtb_39;
        private: System::Windows::Forms::RichTextBox^ rtb_38;
        private: System::Windows::Forms::RichTextBox^ rtb_37;
        private: System::Windows::Forms::RichTextBox^ rtb_36;
        private: System::Windows::Forms::RichTextBox^ rtb_35;
        private: System::Windows::Forms::RichTextBox^ rtb_34;
        private: System::Windows::Forms::RichTextBox^ rtb_33;
        private: System::Windows::Forms::RichTextBox^ rtb_32;
        private: System::Windows::Forms::RichTextBox^ rtb_31;
        private: System::Windows::Forms::RichTextBox^ rtb_30;
        private: System::Windows::Forms::RichTextBox^ rtb_29;
        private: System::Windows::Forms::RichTextBox^ rtb_28;
        private: System::Windows::Forms::RichTextBox^ rtb_27;
        private: System::Windows::Forms::RichTextBox^ richTextBox17;
        private: System::Windows::Forms::RichTextBox^ rtb_52;
        private: System::Windows::Forms::RichTextBox^ rtb_51;
        private: System::Windows::Forms::RichTextBox^ rtb_50;
        private: System::Windows::Forms::RichTextBox^ rtb_49;
        private: System::Windows::Forms::RichTextBox^ rtb_48;
        private: System::Windows::Forms::RichTextBox^ rtb_47;
        private: System::Windows::Forms::RichTextBox^ rtb_46;
        private: System::Windows::Forms::RichTextBox^ rtb_45;
        private: System::Windows::Forms::RichTextBox^ rtb_44;
        private: System::Windows::Forms::RichTextBox^ rtb_43;
        private: System::Windows::Forms::RichTextBox^ rtb_42;
        private: System::Windows::Forms::RichTextBox^ rtb_41;
        private: System::Windows::Forms::RichTextBox^ rtb_40;
        private: System::Windows::Forms::ProgressBar^ progressBar1;
        private: System::Windows::Forms::Label^ label4;
        private: System::Windows::Forms::Label^ label5;
        private: System::Windows::Forms::ProgressBar^ progressBar2;
        private: System::Windows::Forms::Label^ label6;
        private: System::Windows::Forms::Label^ label9;
        private: System::Windows::Forms::Label^ label10;
        private: System::Windows::Forms::Label^ label11;
        private: System::Windows::Forms::Label^ label12;
        private: System::Windows::Forms::Label^ label13;
        private: System::Windows::Forms::Label^ label14;
        private: System::Windows::Forms::Label^ label15;
        private: System::Windows::Forms::Label^ label17;
        private: System::Windows::Forms::Label^ label18;
        private: System::Windows::Forms::Label^ label20;
        private: System::Windows::Forms::Label^ label22;
        private: System::Windows::Forms::Label^ label23;
    private: System::Windows::Forms::Label^ label24;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::RichTextBox^ rtb_76;
    private: System::Windows::Forms::RichTextBox^ rtb_86;
    private: System::Windows::Forms::RichTextBox^ rtb_66;
    private: System::Windows::Forms::RichTextBox^ rtb_75;
    private: System::Windows::Forms::RichTextBox^ rtb_85;
    private: System::Windows::Forms::RichTextBox^ rtb_65;
    private: System::Windows::Forms::RichTextBox^ rtb_74;
    private: System::Windows::Forms::RichTextBox^ rtb_84;
    private: System::Windows::Forms::RichTextBox^ rtb_63;
    private: System::Windows::Forms::RichTextBox^ rtb_73;
    private: System::Windows::Forms::RichTextBox^ rtb_83;
    private: System::Windows::Forms::RichTextBox^ rtb_64;
    private: System::Windows::Forms::RichTextBox^ rtb_72;
    private: System::Windows::Forms::RichTextBox^ rtb_82;
    private: System::Windows::Forms::RichTextBox^ rtb_62;
    private: System::Windows::Forms::RichTextBox^ rtb_71;
    private: System::Windows::Forms::RichTextBox^ rtb_81;
    private: System::Windows::Forms::RichTextBox^ rtb_61;
    private: System::Windows::Forms::RichTextBox^ rtb_70;
    private: System::Windows::Forms::RichTextBox^ rtb_80;
    private: System::Windows::Forms::RichTextBox^ rtb_60;
    private: System::Windows::Forms::TextBox^ tb_Npaneles;
        public: Resultado(void)
        {
            InitializeComponent();
            //
            //TODO: agregar código de constructor aquí
            //
        }
        protected: /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~Resultado()
        {
            if (components)
            {
                delete components;
            }
        }
        protected: private: System::Windows::Forms::Panel^ panel1;
        private: System::Windows::Forms::Label^ label16;
        private: System::Windows::Forms::Button^ b_fich;
        private: System::Windows::Forms::Label^ label21;
        private: System::Windows::Forms::TextBox^ tb_Eanual;
        private: System::Windows::Forms::TextBox^ tb_area;
        private: System::Windows::Forms::Label^ label8;
        private: System::Windows::Forms::Label^ label7;
        private: System::Windows::Forms::Button^ button2;
        private: System::Windows::Forms::TextBox^ tb_precio;
        private: System::Windows::Forms::Label^ label51;
        private: System::Windows::Forms::TextBox^ tb_Voc;
        private: System::Windows::Forms::TextBox^ tb_Isc;
        private: System::Windows::Forms::Label^ label49;
        private: System::Windows::Forms::Label^ label50;
        private: System::Windows::Forms::TextBox^ tb_Imp;
        private: System::Windows::Forms::TextBox^ tb_Pmp;
        private: System::Windows::Forms::Label^ label46;
        private: System::Windows::Forms::Label^ label47;
        private: System::Windows::Forms::Label^ label48;
        private: System::Windows::Forms::TextBox^ tb_Vmp;
        private: System::Windows::Forms::Label^ label45;
        private: System::Windows::Forms::Label^ label1;
        protected: private: /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        ///
        ///
        void InitializeComponent(void)
        {
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->b_fich = (gcnew System::Windows::Forms::Button());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->tb_Eanual = (gcnew System::Windows::Forms::TextBox());
            this->tb_area = (gcnew System::Windows::Forms::TextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->tb_precio = (gcnew System::Windows::Forms::TextBox());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->tb_Voc = (gcnew System::Windows::Forms::TextBox());
            this->tb_Isc = (gcnew System::Windows::Forms::TextBox());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->tb_Imp = (gcnew System::Windows::Forms::TextBox());
            this->tb_Pmp = (gcnew System::Windows::Forms::TextBox());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->tb_Vmp = (gcnew System::Windows::Forms::TextBox());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->tb_Npaneles = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox7 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox8 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox9 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox10 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox11 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox12 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox13 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_1 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_2 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_4 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_3 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_8 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_7 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_6 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_5 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_12 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_11 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_10 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_9 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_13 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox14 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox15 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_26 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_25 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_24 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_23 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_22 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_21 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_20 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_19 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_18 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_17 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_16 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_15 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_14 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox16 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_39 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_38 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_37 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_36 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_35 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_34 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_33 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_32 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_31 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_30 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_29 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_28 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_27 = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBox17 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_52 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_51 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_50 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_49 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_48 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_47 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_46 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_45 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_44 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_43 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_42 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_41 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_40 = (gcnew System::Windows::Forms::RichTextBox());
            this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->rtb_76 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_86 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_66 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_75 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_85 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_65 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_74 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_84 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_63 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_73 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_83 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_64 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_72 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_82 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_62 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_71 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_81 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_61 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_70 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_80 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_60 = (gcnew System::Windows::Forms::RichTextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->panel1->SuspendLayout();
            this->SuspendLayout();
            //
            // panel1
            //
            this->panel1->BackColor = System::Drawing::Color::MidnightBlue;
            this->panel1->Controls->Add(this->label16);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(1924, 98);
            this->panel1->TabIndex = 96;
            //
            // label16
            //
            this->label16->AutoSize = true;
            this->label16->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label16->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->label16->Location = System::Drawing::Point(211, 31);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(239, 31);
            this->label16->TabIndex = 7;
            this->label16->Text = L"ESTUDIO AVANZADO";
            //
            // b_fich
            //
            this->b_fich->BackColor = System::Drawing::Color::Gray;
            this->b_fich->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->b_fich->Location = System::Drawing::Point(331, 358);
            this->b_fich->Name = L"b_fich";
            this->b_fich->Size = System::Drawing::Size(170, 41);
            this->b_fich->TabIndex = 4;
            this->b_fich->Text = L"Buscar en fichero";
            this->b_fich->UseVisualStyleBackColor = false;
            this->b_fich->Click += gcnew System::EventHandler(this, &Resultado::button7_Click);
            //
            // label21
            //
            this->label21->AutoSize = true;
            this->label21->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label21->Location = System::Drawing::Point(213, 251);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(206, 23);
            this->label21->TabIndex = 103;
            this->label21->Text = L"Demanda anual [kW/año]";
            //
            // tb_Eanual
            //
            this->tb_Eanual->Location = System::Drawing::Point(448, 251);
            this->tb_Eanual->Name = L"tb_Eanual";
            this->tb_Eanual->Size = System::Drawing::Size(174, 22);
            this->tb_Eanual->TabIndex = 1;
            //
            // tb_area
            //
            this->tb_area->Location = System::Drawing::Point(398, 816);
            this->tb_area->Name = L"tb_area";
            this->tb_area->Size = System::Drawing::Size(174, 22);
            this->tb_area->TabIndex = 11;
            this->tb_area->Text = L"2.20";
            //
            // label8
            //
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(285, 814);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(10, 12);
            this->label8->TabIndex = 133;
            this->label8->Text = L"2";
            //
            // label7
            //
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(217, 815);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(85, 23);
            this->label7->TabIndex = 132;
            this->label7->Text = L"Area [m  ]";
            //
            // button2
            //
            this->button2->BackColor = System::Drawing::Color::Gray;
            this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(297, 870);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(170, 41);
            this->button2->TabIndex = 12;
            this->button2->Text = L"Actualizar valores";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &Resultado::button2_Click);
            //
            // tb_precio
            //
            this->tb_precio->Location = System::Drawing::Point(398, 773);
            this->tb_precio->Name = L"tb_precio";
            this->tb_precio->Size = System::Drawing::Size(174, 22);
            this->tb_precio->TabIndex = 10;
            this->tb_precio->Text = L"170";
            //
            // label51
            //
            this->label51->AutoSize = true;
            this->label51->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label51->Location = System::Drawing::Point(217, 771);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(81, 23);
            this->label51->TabIndex = 129;
            this->label51->Text = L"Precio [€]";
            //
            // tb_Voc
            //
            this->tb_Voc->Location = System::Drawing::Point(398, 693);
            this->tb_Voc->Name = L"tb_Voc";
            this->tb_Voc->Size = System::Drawing::Size(174, 22);
            this->tb_Voc->TabIndex = 8;
            this->tb_Voc->Text = L"50.43";
            //
            // tb_Isc
            //
            this->tb_Isc->Location = System::Drawing::Point(398, 731);
            this->tb_Isc->Name = L"tb_Isc";
            this->tb_Isc->Size = System::Drawing::Size(174, 22);
            this->tb_Isc->TabIndex = 9;
            this->tb_Isc->Text = L"11.36";
            //
            // label49
            //
            this->label49->AutoSize = true;
            this->label49->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label49->Location = System::Drawing::Point(217, 692);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(64, 23);
            this->label49->TabIndex = 126;
            this->label49->Text = L"Voc [V]";
            //
            // label50
            //
            this->label50->AutoSize = true;
            this->label50->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(217, 730);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(56, 23);
            this->label50->TabIndex = 125;
            this->label50->Text = L"Isc [A]";
            //
            // tb_Imp
            //
            this->tb_Imp->Location = System::Drawing::Point(396, 615);
            this->tb_Imp->Name = L"tb_Imp";
            this->tb_Imp->Size = System::Drawing::Size(174, 22);
            this->tb_Imp->TabIndex = 6;
            this->tb_Imp->Text = L"10.7";
            //
            // tb_Pmp
            //
            this->tb_Pmp->Location = System::Drawing::Point(396, 653);
            this->tb_Pmp->Name = L"tb_Pmp";
            this->tb_Pmp->Size = System::Drawing::Size(174, 22);
            this->tb_Pmp->TabIndex = 7;
            this->tb_Pmp->Text = L"450";
            //
            // label46
            //
            this->label46->AutoSize = true;
            this->label46->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(217, 614);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(66, 23);
            this->label46->TabIndex = 122;
            this->label46->Text = L"Imp [A]";
            //
            // label47
            //
            this->label47->AutoSize = true;
            this->label47->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label47->Location = System::Drawing::Point(215, 652);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(85, 23);
            this->label47->TabIndex = 121;
            this->label47->Text = L"Pmp [Wp]";
            //
            // label48
            //
            this->label48->AutoSize = true;
            this->label48->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label48->Location = System::Drawing::Point(217, 570);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(71, 23);
            this->label48->TabIndex = 120;
            this->label48->Text = L"Vmp [V]";
            //
            // tb_Vmp
            //
            this->tb_Vmp->Location = System::Drawing::Point(396, 572);
            this->tb_Vmp->Name = L"tb_Vmp";
            this->tb_Vmp->Size = System::Drawing::Size(174, 22);
            this->tb_Vmp->TabIndex = 5;
            this->tb_Vmp->Text = L"42.06";
            //
            // label45
            //
            this->label45->AutoSize = true;
            this->label45->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label45->Location = System::Drawing::Point(211, 510);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(238, 31);
            this->label45->TabIndex = 118;
            this->label45->Text = L"2. Selección del panel";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(211, 191);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(264, 31);
            this->label1->TabIndex = 135;
            this->label1->Text = L"1. Introducción de datos";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(213, 296);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(160, 23);
            this->label2->TabIndex = 137;
            this->label2->Text = L"Número de paneles";
            //
            // tb_Npaneles
            //
            this->tb_Npaneles->Location = System::Drawing::Point(448, 296);
            this->tb_Npaneles->Name = L"tb_Npaneles";
            this->tb_Npaneles->Size = System::Drawing::Size(174, 22);
            this->tb_Npaneles->TabIndex = 2;
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(719, 191);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(178, 31);
            this->label3->TabIndex = 138;
            this->label3->Text = L"3. RESULTADOS";
            this->label3->Visible = false;
            //
            // richTextBox1
            //
            this->richTextBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(725, 277);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->ReadOnly = true;
            this->richTextBox1->Size = System::Drawing::Size(108, 26);
            this->richTextBox1->TabIndex = 187;
            this->richTextBox1->Text = L"      Enero";
            this->richTextBox1->Visible = false;
            //
            // richTextBox2
            //
            this->richTextBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox2->Location = System::Drawing::Point(725, 309);
            this->richTextBox2->Name = L"richTextBox2";
            this->richTextBox2->ReadOnly = true;
            this->richTextBox2->Size = System::Drawing::Size(108, 26);
            this->richTextBox2->TabIndex = 188;
            this->richTextBox2->Text = L"    Febrero";
            this->richTextBox2->Visible = false;
            //
            // richTextBox3
            //
            this->richTextBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox3->Location = System::Drawing::Point(725, 341);
            this->richTextBox3->Name = L"richTextBox3";
            this->richTextBox3->ReadOnly = true;
            this->richTextBox3->Size = System::Drawing::Size(108, 26);
            this->richTextBox3->TabIndex = 189;
            this->richTextBox3->Text = L"      Marzo";
            this->richTextBox3->Visible = false;
            //
            // richTextBox4
            //
            this->richTextBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox4->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox4->Location = System::Drawing::Point(725, 373);
            this->richTextBox4->Name = L"richTextBox4";
            this->richTextBox4->ReadOnly = true;
            this->richTextBox4->Size = System::Drawing::Size(108, 26);
            this->richTextBox4->TabIndex = 190;
            this->richTextBox4->Text = L"      Abril";
            this->richTextBox4->Visible = false;
            //
            // richTextBox5
            //
            this->richTextBox5->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox5->Location = System::Drawing::Point(725, 403);
            this->richTextBox5->Name = L"richTextBox5";
            this->richTextBox5->ReadOnly = true;
            this->richTextBox5->Size = System::Drawing::Size(108, 26);
            this->richTextBox5->TabIndex = 191;
            this->richTextBox5->Text = L"      Mayo";
            this->richTextBox5->Visible = false;
            //
            // richTextBox6
            //
            this->richTextBox6->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox6->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox6->Location = System::Drawing::Point(725, 435);
            this->richTextBox6->Name = L"richTextBox6";
            this->richTextBox6->ReadOnly = true;
            this->richTextBox6->Size = System::Drawing::Size(108, 26);
            this->richTextBox6->TabIndex = 192;
            this->richTextBox6->Text = L"      Junio";
            this->richTextBox6->Visible = false;
            //
            // richTextBox7
            //
            this->richTextBox7->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox7->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox7->Location = System::Drawing::Point(725, 467);
            this->richTextBox7->Name = L"richTextBox7";
            this->richTextBox7->ReadOnly = true;
            this->richTextBox7->Size = System::Drawing::Size(108, 26);
            this->richTextBox7->TabIndex = 193;
            this->richTextBox7->Text = L"      Julio";
            this->richTextBox7->Visible = false;
            //
            // richTextBox8
            //
            this->richTextBox8->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox8->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox8->Location = System::Drawing::Point(725, 499);
            this->richTextBox8->Name = L"richTextBox8";
            this->richTextBox8->ReadOnly = true;
            this->richTextBox8->Size = System::Drawing::Size(108, 26);
            this->richTextBox8->TabIndex = 194;
            this->richTextBox8->Text = L"     Agosto";
            this->richTextBox8->Visible = false;
            //
            // richTextBox9
            //
            this->richTextBox9->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox9->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox9->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox9->Location = System::Drawing::Point(725, 531);
            this->richTextBox9->Name = L"richTextBox9";
            this->richTextBox9->ReadOnly = true;
            this->richTextBox9->Size = System::Drawing::Size(108, 26);
            this->richTextBox9->TabIndex = 195;
            this->richTextBox9->Text = L"  Septiembre";
            this->richTextBox9->Visible = false;
            //
            // richTextBox10
            //
            this->richTextBox10->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox10->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox10->Location = System::Drawing::Point(725, 563);
            this->richTextBox10->Name = L"richTextBox10";
            this->richTextBox10->ReadOnly = true;
            this->richTextBox10->Size = System::Drawing::Size(108, 26);
            this->richTextBox10->TabIndex = 196;
            this->richTextBox10->Text = L"    Octubre";
            this->richTextBox10->Visible = false;
            //
            // richTextBox11
            //
            this->richTextBox11->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox11->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox11->Location = System::Drawing::Point(725, 596);
            this->richTextBox11->Name = L"richTextBox11";
            this->richTextBox11->ReadOnly = true;
            this->richTextBox11->Size = System::Drawing::Size(108, 26);
            this->richTextBox11->TabIndex = 197;
            this->richTextBox11->Text = L"  Noviembre";
            this->richTextBox11->Visible = false;
            //
            // richTextBox12
            //
            this->richTextBox12->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox12->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox12->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox12->Location = System::Drawing::Point(725, 628);
            this->richTextBox12->Name = L"richTextBox12";
            this->richTextBox12->ReadOnly = true;
            this->richTextBox12->Size = System::Drawing::Size(108, 26);
            this->richTextBox12->TabIndex = 198;
            this->richTextBox12->Text = L"   Diciembre";
            this->richTextBox12->Visible = false;
            //
            // richTextBox13
            //
            this->richTextBox13->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox13->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox13->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox13->Location = System::Drawing::Point(725, 660);
            this->richTextBox13->Name = L"richTextBox13";
            this->richTextBox13->ReadOnly = true;
            this->richTextBox13->Size = System::Drawing::Size(108, 26);
            this->richTextBox13->TabIndex = 199;
            this->richTextBox13->Text = L"     TOTAL";
            this->richTextBox13->Visible = false;
            //
            // rtb_1
            //
            this->rtb_1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_1->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_1->Location = System::Drawing::Point(839, 277);
            this->rtb_1->Name = L"rtb_1";
            this->rtb_1->ReadOnly = true;
            this->rtb_1->Size = System::Drawing::Size(108, 26);
            this->rtb_1->TabIndex = 200;
            this->rtb_1->Text = L"       100";
            this->rtb_1->Visible = false;
            //
            // rtb_2
            //
            this->rtb_2->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_2->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_2->Location = System::Drawing::Point(839, 309);
            this->rtb_2->Name = L"rtb_2";
            this->rtb_2->ReadOnly = true;
            this->rtb_2->Size = System::Drawing::Size(108, 26);
            this->rtb_2->TabIndex = 201;
            this->rtb_2->Text = L"       100";
            this->rtb_2->Visible = false;
            //
            // rtb_4
            //
            this->rtb_4->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_4->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_4->Location = System::Drawing::Point(839, 373);
            this->rtb_4->Name = L"rtb_4";
            this->rtb_4->ReadOnly = true;
            this->rtb_4->Size = System::Drawing::Size(108, 26);
            this->rtb_4->TabIndex = 203;
            this->rtb_4->Text = L"       100";
            this->rtb_4->Visible = false;
            //
            // rtb_3
            //
            this->rtb_3->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_3->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_3->Location = System::Drawing::Point(839, 341);
            this->rtb_3->Name = L"rtb_3";
            this->rtb_3->ReadOnly = true;
            this->rtb_3->Size = System::Drawing::Size(108, 26);
            this->rtb_3->TabIndex = 202;
            this->rtb_3->Text = L"       100";
            this->rtb_3->Visible = false;
            //
            // rtb_8
            //
            this->rtb_8->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_8->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_8->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_8->Location = System::Drawing::Point(839, 499);
            this->rtb_8->Name = L"rtb_8";
            this->rtb_8->ReadOnly = true;
            this->rtb_8->Size = System::Drawing::Size(108, 26);
            this->rtb_8->TabIndex = 207;
            this->rtb_8->Text = L"       100";
            this->rtb_8->Visible = false;
            //
            // rtb_7
            //
            this->rtb_7->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_7->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_7->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_7->Location = System::Drawing::Point(839, 467);
            this->rtb_7->Name = L"rtb_7";
            this->rtb_7->ReadOnly = true;
            this->rtb_7->Size = System::Drawing::Size(108, 26);
            this->rtb_7->TabIndex = 206;
            this->rtb_7->Text = L"       100";
            this->rtb_7->Visible = false;
            //
            // rtb_6
            //
            this->rtb_6->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_6->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_6->Location = System::Drawing::Point(839, 435);
            this->rtb_6->Name = L"rtb_6";
            this->rtb_6->ReadOnly = true;
            this->rtb_6->Size = System::Drawing::Size(108, 26);
            this->rtb_6->TabIndex = 205;
            this->rtb_6->Text = L"       100";
            this->rtb_6->Visible = false;
            //
            // rtb_5
            //
            this->rtb_5->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_5->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_5->Location = System::Drawing::Point(839, 403);
            this->rtb_5->Name = L"rtb_5";
            this->rtb_5->ReadOnly = true;
            this->rtb_5->Size = System::Drawing::Size(108, 26);
            this->rtb_5->TabIndex = 204;
            this->rtb_5->Text = L"       100";
            this->rtb_5->Visible = false;
            //
            // rtb_12
            //
            this->rtb_12->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_12->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_12->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_12->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_12->Location = System::Drawing::Point(839, 627);
            this->rtb_12->Name = L"rtb_12";
            this->rtb_12->ReadOnly = true;
            this->rtb_12->Size = System::Drawing::Size(108, 26);
            this->rtb_12->TabIndex = 211;
            this->rtb_12->Text = L"       100";
            this->rtb_12->Visible = false;
            //
            // rtb_11
            //
            this->rtb_11->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_11->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_11->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_11->Location = System::Drawing::Point(839, 595);
            this->rtb_11->Name = L"rtb_11";
            this->rtb_11->ReadOnly = true;
            this->rtb_11->Size = System::Drawing::Size(108, 26);
            this->rtb_11->TabIndex = 210;
            this->rtb_11->Text = L"       100";
            this->rtb_11->Visible = false;
            //
            // rtb_10
            //
            this->rtb_10->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_10->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_10->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_10->Location = System::Drawing::Point(839, 563);
            this->rtb_10->Name = L"rtb_10";
            this->rtb_10->ReadOnly = true;
            this->rtb_10->Size = System::Drawing::Size(108, 26);
            this->rtb_10->TabIndex = 209;
            this->rtb_10->Text = L"       100";
            this->rtb_10->Visible = false;
            //
            // rtb_9
            //
            this->rtb_9->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_9->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_9->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_9->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_9->Location = System::Drawing::Point(839, 531);
            this->rtb_9->Name = L"rtb_9";
            this->rtb_9->ReadOnly = true;
            this->rtb_9->Size = System::Drawing::Size(108, 26);
            this->rtb_9->TabIndex = 208;
            this->rtb_9->Text = L"       100";
            this->rtb_9->Visible = false;
            //
            // rtb_13
            //
            this->rtb_13->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_13->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_13->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_13->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_13->Location = System::Drawing::Point(839, 660);
            this->rtb_13->Name = L"rtb_13";
            this->rtb_13->ReadOnly = true;
            this->rtb_13->Size = System::Drawing::Size(108, 26);
            this->rtb_13->TabIndex = 212;
            this->rtb_13->Text = L"       100";
            this->rtb_13->Visible = false;
            //
            // richTextBox14
            //
            this->richTextBox14->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox14->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox14->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox14->Location = System::Drawing::Point(839, 244);
            this->richTextBox14->Name = L"richTextBox14";
            this->richTextBox14->ReadOnly = true;
            this->richTextBox14->Size = System::Drawing::Size(108, 27);
            this->richTextBox14->TabIndex = 213;
            this->richTextBox14->Text = L"    Consumo kW    ";
            this->richTextBox14->Visible = false;
            //
            // richTextBox15
            //
            this->richTextBox15->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox15->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox15->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox15->Location = System::Drawing::Point(953, 244);
            this->richTextBox15->Name = L"richTextBox15";
            this->richTextBox15->ReadOnly = true;
            this->richTextBox15->Size = System::Drawing::Size(108, 27);
            this->richTextBox15->TabIndex = 227;
            this->richTextBox15->Text = L"  Generación kW     ";
            this->richTextBox15->Visible = false;
            //
            // rtb_26
            //
            this->rtb_26->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_26->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_26->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_26->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_26->Location = System::Drawing::Point(953, 660);
            this->rtb_26->Name = L"rtb_26";
            this->rtb_26->ReadOnly = true;
            this->rtb_26->Size = System::Drawing::Size(108, 26);
            this->rtb_26->TabIndex = 226;
            this->rtb_26->Text = L"       100";
            this->rtb_26->Visible = false;
            //
            // rtb_25
            //
            this->rtb_25->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_25->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_25->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_25->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_25->Location = System::Drawing::Point(953, 627);
            this->rtb_25->Name = L"rtb_25";
            this->rtb_25->ReadOnly = true;
            this->rtb_25->Size = System::Drawing::Size(108, 26);
            this->rtb_25->TabIndex = 225;
            this->rtb_25->Text = L"       100";
            this->rtb_25->Visible = false;
            //
            // rtb_24
            //
            this->rtb_24->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_24->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_24->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_24->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_24->Location = System::Drawing::Point(953, 595);
            this->rtb_24->Name = L"rtb_24";
            this->rtb_24->ReadOnly = true;
            this->rtb_24->Size = System::Drawing::Size(108, 26);
            this->rtb_24->TabIndex = 224;
            this->rtb_24->Text = L"       100";
            this->rtb_24->Visible = false;
            //
            // rtb_23
            //
            this->rtb_23->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_23->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_23->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_23->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_23->Location = System::Drawing::Point(953, 563);
            this->rtb_23->Name = L"rtb_23";
            this->rtb_23->ReadOnly = true;
            this->rtb_23->Size = System::Drawing::Size(108, 26);
            this->rtb_23->TabIndex = 223;
            this->rtb_23->Text = L"       100";
            this->rtb_23->Visible = false;
            //
            // rtb_22
            //
            this->rtb_22->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_22->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_22->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_22->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_22->Location = System::Drawing::Point(953, 531);
            this->rtb_22->Name = L"rtb_22";
            this->rtb_22->ReadOnly = true;
            this->rtb_22->Size = System::Drawing::Size(108, 26);
            this->rtb_22->TabIndex = 222;
            this->rtb_22->Text = L"       100";
            this->rtb_22->Visible = false;
            //
            // rtb_21
            //
            this->rtb_21->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_21->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_21->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_21->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_21->Location = System::Drawing::Point(953, 499);
            this->rtb_21->Name = L"rtb_21";
            this->rtb_21->ReadOnly = true;
            this->rtb_21->Size = System::Drawing::Size(108, 26);
            this->rtb_21->TabIndex = 221;
            this->rtb_21->Text = L"       100";
            this->rtb_21->Visible = false;
            //
            // rtb_20
            //
            this->rtb_20->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_20->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_20->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_20->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_20->Location = System::Drawing::Point(953, 467);
            this->rtb_20->Name = L"rtb_20";
            this->rtb_20->ReadOnly = true;
            this->rtb_20->Size = System::Drawing::Size(108, 26);
            this->rtb_20->TabIndex = 220;
            this->rtb_20->Text = L"       100";
            this->rtb_20->Visible = false;
            //
            // rtb_19
            //
            this->rtb_19->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_19->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_19->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_19->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_19->Location = System::Drawing::Point(953, 435);
            this->rtb_19->Name = L"rtb_19";
            this->rtb_19->ReadOnly = true;
            this->rtb_19->Size = System::Drawing::Size(108, 26);
            this->rtb_19->TabIndex = 219;
            this->rtb_19->Text = L"       100";
            this->rtb_19->Visible = false;
            //
            // rtb_18
            //
            this->rtb_18->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_18->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_18->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_18->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_18->Location = System::Drawing::Point(953, 403);
            this->rtb_18->Name = L"rtb_18";
            this->rtb_18->ReadOnly = true;
            this->rtb_18->Size = System::Drawing::Size(108, 26);
            this->rtb_18->TabIndex = 218;
            this->rtb_18->Text = L"       100";
            this->rtb_18->Visible = false;
            //
            // rtb_17
            //
            this->rtb_17->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_17->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_17->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_17->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_17->Location = System::Drawing::Point(953, 373);
            this->rtb_17->Name = L"rtb_17";
            this->rtb_17->ReadOnly = true;
            this->rtb_17->Size = System::Drawing::Size(108, 26);
            this->rtb_17->TabIndex = 217;
            this->rtb_17->Text = L"       100";
            this->rtb_17->Visible = false;
            //
            // rtb_16
            //
            this->rtb_16->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_16->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_16->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_16->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_16->Location = System::Drawing::Point(953, 341);
            this->rtb_16->Name = L"rtb_16";
            this->rtb_16->ReadOnly = true;
            this->rtb_16->Size = System::Drawing::Size(108, 26);
            this->rtb_16->TabIndex = 216;
            this->rtb_16->Text = L"       100";
            this->rtb_16->Visible = false;
            //
            // rtb_15
            //
            this->rtb_15->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_15->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_15->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_15->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_15->Location = System::Drawing::Point(953, 309);
            this->rtb_15->Name = L"rtb_15";
            this->rtb_15->ReadOnly = true;
            this->rtb_15->Size = System::Drawing::Size(108, 26);
            this->rtb_15->TabIndex = 215;
            this->rtb_15->Text = L"       100";
            this->rtb_15->Visible = false;
            //
            // rtb_14
            //
            this->rtb_14->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_14->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_14->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_14->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_14->Location = System::Drawing::Point(953, 277);
            this->rtb_14->Name = L"rtb_14";
            this->rtb_14->ReadOnly = true;
            this->rtb_14->Size = System::Drawing::Size(108, 26);
            this->rtb_14->TabIndex = 214;
            this->rtb_14->Text = L"       100";
            this->rtb_14->Visible = false;
            //
            // richTextBox16
            //
            this->richTextBox16->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox16->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox16->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox16->Location = System::Drawing::Point(1067, 244);
            this->richTextBox16->Name = L"richTextBox16";
            this->richTextBox16->ReadOnly = true;
            this->richTextBox16->Size = System::Drawing::Size(108, 27);
            this->richTextBox16->TabIndex = 241;
            this->richTextBox16->Text = L"  Excedentes kW     ";
            this->richTextBox16->Visible = false;
            //
            // rtb_39
            //
            this->rtb_39->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_39->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_39->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_39->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_39->Location = System::Drawing::Point(1067, 660);
            this->rtb_39->Name = L"rtb_39";
            this->rtb_39->ReadOnly = true;
            this->rtb_39->Size = System::Drawing::Size(108, 26);
            this->rtb_39->TabIndex = 240;
            this->rtb_39->Text = L"       100";
            this->rtb_39->Visible = false;
            //
            // rtb_38
            //
            this->rtb_38->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_38->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_38->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_38->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_38->Location = System::Drawing::Point(1067, 627);
            this->rtb_38->Name = L"rtb_38";
            this->rtb_38->ReadOnly = true;
            this->rtb_38->Size = System::Drawing::Size(108, 26);
            this->rtb_38->TabIndex = 239;
            this->rtb_38->Text = L"       100";
            this->rtb_38->Visible = false;
            //
            // rtb_37
            //
            this->rtb_37->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_37->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_37->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_37->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_37->Location = System::Drawing::Point(1067, 595);
            this->rtb_37->Name = L"rtb_37";
            this->rtb_37->ReadOnly = true;
            this->rtb_37->Size = System::Drawing::Size(108, 26);
            this->rtb_37->TabIndex = 238;
            this->rtb_37->Text = L"       100";
            this->rtb_37->Visible = false;
            //
            // rtb_36
            //
            this->rtb_36->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_36->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_36->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_36->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_36->Location = System::Drawing::Point(1067, 563);
            this->rtb_36->Name = L"rtb_36";
            this->rtb_36->ReadOnly = true;
            this->rtb_36->Size = System::Drawing::Size(108, 26);
            this->rtb_36->TabIndex = 237;
            this->rtb_36->Text = L"       100";
            this->rtb_36->Visible = false;
            //
            // rtb_35
            //
            this->rtb_35->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_35->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_35->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_35->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_35->Location = System::Drawing::Point(1067, 531);
            this->rtb_35->Name = L"rtb_35";
            this->rtb_35->ReadOnly = true;
            this->rtb_35->Size = System::Drawing::Size(108, 26);
            this->rtb_35->TabIndex = 236;
            this->rtb_35->Text = L"       100";
            this->rtb_35->Visible = false;
            //
            // rtb_34
            //
            this->rtb_34->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_34->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_34->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_34->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_34->Location = System::Drawing::Point(1067, 499);
            this->rtb_34->Name = L"rtb_34";
            this->rtb_34->ReadOnly = true;
            this->rtb_34->Size = System::Drawing::Size(108, 26);
            this->rtb_34->TabIndex = 235;
            this->rtb_34->Text = L"       100";
            this->rtb_34->Visible = false;
            //
            // rtb_33
            //
            this->rtb_33->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_33->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_33->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_33->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_33->Location = System::Drawing::Point(1067, 467);
            this->rtb_33->Name = L"rtb_33";
            this->rtb_33->ReadOnly = true;
            this->rtb_33->Size = System::Drawing::Size(108, 26);
            this->rtb_33->TabIndex = 234;
            this->rtb_33->Text = L"       100";
            this->rtb_33->Visible = false;
            //
            // rtb_32
            //
            this->rtb_32->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_32->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_32->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_32->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_32->Location = System::Drawing::Point(1067, 435);
            this->rtb_32->Name = L"rtb_32";
            this->rtb_32->ReadOnly = true;
            this->rtb_32->Size = System::Drawing::Size(108, 26);
            this->rtb_32->TabIndex = 233;
            this->rtb_32->Text = L"       100";
            this->rtb_32->Visible = false;
            //
            // rtb_31
            //
            this->rtb_31->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_31->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_31->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_31->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_31->Location = System::Drawing::Point(1067, 403);
            this->rtb_31->Name = L"rtb_31";
            this->rtb_31->ReadOnly = true;
            this->rtb_31->Size = System::Drawing::Size(108, 26);
            this->rtb_31->TabIndex = 232;
            this->rtb_31->Text = L"       100";
            this->rtb_31->Visible = false;
            //
            // rtb_30
            //
            this->rtb_30->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_30->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_30->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_30->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_30->Location = System::Drawing::Point(1067, 373);
            this->rtb_30->Name = L"rtb_30";
            this->rtb_30->ReadOnly = true;
            this->rtb_30->Size = System::Drawing::Size(108, 26);
            this->rtb_30->TabIndex = 231;
            this->rtb_30->Text = L"       100";
            this->rtb_30->Visible = false;
            //
            // rtb_29
            //
            this->rtb_29->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_29->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_29->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_29->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_29->Location = System::Drawing::Point(1067, 341);
            this->rtb_29->Name = L"rtb_29";
            this->rtb_29->ReadOnly = true;
            this->rtb_29->Size = System::Drawing::Size(108, 26);
            this->rtb_29->TabIndex = 230;
            this->rtb_29->Text = L"       100";
            this->rtb_29->Visible = false;
            //
            // rtb_28
            //
            this->rtb_28->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_28->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_28->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_28->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_28->Location = System::Drawing::Point(1067, 309);
            this->rtb_28->Name = L"rtb_28";
            this->rtb_28->ReadOnly = true;
            this->rtb_28->Size = System::Drawing::Size(108, 26);
            this->rtb_28->TabIndex = 229;
            this->rtb_28->Text = L"       100";
            this->rtb_28->Visible = false;
            //
            // rtb_27
            //
            this->rtb_27->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_27->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_27->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_27->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_27->Location = System::Drawing::Point(1067, 277);
            this->rtb_27->Name = L"rtb_27";
            this->rtb_27->ReadOnly = true;
            this->rtb_27->Size = System::Drawing::Size(108, 26);
            this->rtb_27->TabIndex = 228;
            this->rtb_27->Text = L"       100";
            this->rtb_27->Visible = false;
            //
            // richTextBox17
            //
            this->richTextBox17->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->richTextBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->richTextBox17->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->richTextBox17->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->richTextBox17->Location = System::Drawing::Point(1181, 244);
            this->richTextBox17->Name = L"richTextBox17";
            this->richTextBox17->ReadOnly = true;
            this->richTextBox17->Size = System::Drawing::Size(116, 27);
            this->richTextBox17->TabIndex = 255;
            this->richTextBox17->Text = L"Autoconsumo  kW   ";
            this->richTextBox17->Visible = false;
            //
            // rtb_52
            //
            this->rtb_52->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_52->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_52->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_52->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_52->Location = System::Drawing::Point(1181, 660);
            this->rtb_52->Name = L"rtb_52";
            this->rtb_52->ReadOnly = true;
            this->rtb_52->Size = System::Drawing::Size(116, 26);
            this->rtb_52->TabIndex = 254;
            this->rtb_52->Text = L"       100";
            this->rtb_52->Visible = false;
            //
            // rtb_51
            //
            this->rtb_51->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_51->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_51->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_51->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_51->Location = System::Drawing::Point(1181, 627);
            this->rtb_51->Name = L"rtb_51";
            this->rtb_51->ReadOnly = true;
            this->rtb_51->Size = System::Drawing::Size(116, 26);
            this->rtb_51->TabIndex = 253;
            this->rtb_51->Text = L"       100";
            this->rtb_51->Visible = false;
            //
            // rtb_50
            //
            this->rtb_50->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_50->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_50->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_50->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_50->Location = System::Drawing::Point(1181, 595);
            this->rtb_50->Name = L"rtb_50";
            this->rtb_50->ReadOnly = true;
            this->rtb_50->Size = System::Drawing::Size(116, 26);
            this->rtb_50->TabIndex = 252;
            this->rtb_50->Text = L"       100";
            this->rtb_50->Visible = false;
            //
            // rtb_49
            //
            this->rtb_49->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_49->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_49->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_49->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_49->Location = System::Drawing::Point(1181, 563);
            this->rtb_49->Name = L"rtb_49";
            this->rtb_49->ReadOnly = true;
            this->rtb_49->Size = System::Drawing::Size(116, 26);
            this->rtb_49->TabIndex = 251;
            this->rtb_49->Text = L"       100";
            this->rtb_49->Visible = false;
            //
            // rtb_48
            //
            this->rtb_48->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_48->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_48->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_48->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_48->Location = System::Drawing::Point(1181, 531);
            this->rtb_48->Name = L"rtb_48";
            this->rtb_48->ReadOnly = true;
            this->rtb_48->Size = System::Drawing::Size(116, 26);
            this->rtb_48->TabIndex = 250;
            this->rtb_48->Text = L"       100";
            this->rtb_48->Visible = false;
            //
            // rtb_47
            //
            this->rtb_47->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_47->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_47->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_47->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_47->Location = System::Drawing::Point(1181, 499);
            this->rtb_47->Name = L"rtb_47";
            this->rtb_47->ReadOnly = true;
            this->rtb_47->Size = System::Drawing::Size(116, 26);
            this->rtb_47->TabIndex = 249;
            this->rtb_47->Text = L"       100";
            this->rtb_47->Visible = false;
            //
            // rtb_46
            //
            this->rtb_46->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_46->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_46->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_46->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_46->Location = System::Drawing::Point(1181, 467);
            this->rtb_46->Name = L"rtb_46";
            this->rtb_46->ReadOnly = true;
            this->rtb_46->Size = System::Drawing::Size(116, 26);
            this->rtb_46->TabIndex = 248;
            this->rtb_46->Text = L"       100";
            this->rtb_46->Visible = false;
            //
            // rtb_45
            //
            this->rtb_45->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_45->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_45->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_45->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_45->Location = System::Drawing::Point(1181, 435);
            this->rtb_45->Name = L"rtb_45";
            this->rtb_45->ReadOnly = true;
            this->rtb_45->Size = System::Drawing::Size(116, 26);
            this->rtb_45->TabIndex = 247;
            this->rtb_45->Text = L"       100";
            this->rtb_45->Visible = false;
            //
            // rtb_44
            //
            this->rtb_44->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_44->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_44->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_44->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_44->Location = System::Drawing::Point(1181, 403);
            this->rtb_44->Name = L"rtb_44";
            this->rtb_44->ReadOnly = true;
            this->rtb_44->Size = System::Drawing::Size(116, 26);
            this->rtb_44->TabIndex = 246;
            this->rtb_44->Text = L"       100";
            this->rtb_44->Visible = false;
            //
            // rtb_43
            //
            this->rtb_43->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_43->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_43->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_43->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_43->Location = System::Drawing::Point(1181, 373);
            this->rtb_43->Name = L"rtb_43";
            this->rtb_43->ReadOnly = true;
            this->rtb_43->Size = System::Drawing::Size(116, 26);
            this->rtb_43->TabIndex = 245;
            this->rtb_43->Text = L"       100";
            this->rtb_43->Visible = false;
            //
            // rtb_42
            //
            this->rtb_42->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_42->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_42->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_42->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_42->Location = System::Drawing::Point(1181, 341);
            this->rtb_42->Name = L"rtb_42";
            this->rtb_42->ReadOnly = true;
            this->rtb_42->Size = System::Drawing::Size(116, 26);
            this->rtb_42->TabIndex = 244;
            this->rtb_42->Text = L"       100";
            this->rtb_42->Visible = false;
            //
            // rtb_41
            //
            this->rtb_41->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_41->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_41->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_41->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_41->Location = System::Drawing::Point(1181, 309);
            this->rtb_41->Name = L"rtb_41";
            this->rtb_41->ReadOnly = true;
            this->rtb_41->Size = System::Drawing::Size(116, 26);
            this->rtb_41->TabIndex = 243;
            this->rtb_41->Text = L"       100";
            this->rtb_41->Visible = false;
            //
            // rtb_40
            //
            this->rtb_40->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_40->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_40->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_40->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_40->Location = System::Drawing::Point(1181, 277);
            this->rtb_40->Name = L"rtb_40";
            this->rtb_40->ReadOnly = true;
            this->rtb_40->Size = System::Drawing::Size(116, 26);
            this->rtb_40->TabIndex = 242;
            this->rtb_40->Text = L"       100";
            this->rtb_40->Visible = false;
            //
            // progressBar1
            //
            this->progressBar1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->progressBar1->Location = System::Drawing::Point(1158, 730);
            this->progressBar1->Name = L"progressBar1";
            this->progressBar1->Size = System::Drawing::Size(153, 23);
            this->progressBar1->TabIndex = 256;
            this->progressBar1->Visible = false;
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(721, 730);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(249, 23);
            this->label4->TabIndex = 257;
            this->label4->Text = L"Auotoconsumo sobre consumo";
            this->label4->Visible = false;
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(721, 771);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(265, 23);
            this->label5->TabIndex = 258;
            this->label5->Text = L"Auotoconsumo sobre producción";
            this->label5->Visible = false;
            //
            // progressBar2
            //
            this->progressBar2->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->progressBar2->Location = System::Drawing::Point(1158, 771);
            this->progressBar2->Name = L"progressBar2";
            this->progressBar2->Size = System::Drawing::Size(153, 23);
            this->progressBar2->TabIndex = 259;
            this->progressBar2->Visible = false;
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(1014, 730);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(47, 23);
            this->label6->TabIndex = 260;
            this->label6->Text = L"30 %";
            this->label6->Visible = false;
            //
            // label9
            //
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(1014, 771);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(47, 23);
            this->label9->TabIndex = 261;
            this->label9->Text = L"30 %";
            this->label9->Visible = false;
            //
            // label10
            //
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(1114, 730);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(24, 23);
            this->label10->TabIndex = 262;
            this->label10->Text = L"%";
            this->label10->Visible = false;
            //
            // label11
            //
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(1114, 771);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(24, 23);
            this->label11->TabIndex = 263;
            this->label11->Text = L"%";
            this->label11->Visible = false;
            //
            // label12
            //
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(721, 811);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(279, 23);
            this->label12->TabIndex = 264;
            this->label12->Text = L"Ahorro por energía autoconsumida";
            this->label12->Visible = false;
            //
            // label13
            //
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(721, 854);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(323, 23);
            this->label13->TabIndex = 265;
            this->label13->Text = L"Ahorro por compensación de excedentes";
            this->label13->Visible = false;
            //
            // label14
            //
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label14->Location = System::Drawing::Point(1091, 811);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(47, 23);
            this->label14->TabIndex = 266;
            this->label14->Text = L"30 %";
            this->label14->Visible = false;
            //
            // label15
            //
            this->label15->AutoSize = true;
            this->label15->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label15->Location = System::Drawing::Point(1091, 854);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(47, 23);
            this->label15->TabIndex = 267;
            this->label15->Text = L"30 %";
            this->label15->Visible = false;
            //
            // label17
            //
            this->label17->AutoSize = true;
            this->label17->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label17->Location = System::Drawing::Point(1219, 811);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(55, 23);
            this->label17->TabIndex = 268;
            this->label17->Text = L"€/año";
            this->label17->Visible = false;
            //
            // label18
            //
            this->label18->AutoSize = true;
            this->label18->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(1219, 854);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(55, 23);
            this->label18->TabIndex = 269;
            this->label18->Text = L"€/año";
            this->label18->Visible = false;
            //
            // label20
            //
            this->label20->AutoSize = true;
            this->label20->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label20->Location = System::Drawing::Point(721, 896);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(275, 23);
            this->label20->TabIndex = 272;
            this->label20->Text = L"Tiempo para recuperar la inversión";
            this->label20->Visible = false;
            //
            // label22
            //
            this->label22->AutoSize = true;
            this->label22->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(1063, 896);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(19, 23);
            this->label22->TabIndex = 273;
            this->label22->Text = L"5";
            this->label22->Visible = false;
            //
            // label23
            //
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(1177, 896);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(46, 23);
            this->label23->TabIndex = 274;
            this->label23->Text = L"años";
            this->label23->Visible = false;
            //
            // label24
            //
            this->label24->AutoSize = true;
            this->label24->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(1359, 191);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(344, 31);
            this->label24->TabIndex = 319;
            this->label24->Text = L"4. DESGLOSE DE LA INVERSIÓN";
            this->label24->Visible = false;
            //
            // rtb_76
            //
            this->rtb_76->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_76->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_76->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_76->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_76->Location = System::Drawing::Point(1524, 461);
            this->rtb_76->Name = L"rtb_76";
            this->rtb_76->ReadOnly = true;
            this->rtb_76->Size = System::Drawing::Size(134, 32);
            this->rtb_76->TabIndex = 318;
            this->rtb_76->Text = L"            -";
            this->rtb_76->Visible = false;
            //
            // rtb_86
            //
            this->rtb_86->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_86->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_86->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_86->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_86->Location = System::Drawing::Point(1664, 461);
            this->rtb_86->Name = L"rtb_86";
            this->rtb_86->ReadOnly = true;
            this->rtb_86->Size = System::Drawing::Size(129, 32);
            this->rtb_86->TabIndex = 317;
            this->rtb_86->Text = L"        Coste";
            this->rtb_86->Visible = false;
            //
            // rtb_66
            //
            this->rtb_66->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_66->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_66->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_66->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_66->Location = System::Drawing::Point(1361, 461);
            this->rtb_66->Name = L"rtb_66";
            this->rtb_66->ReadOnly = true;
            this->rtb_66->Size = System::Drawing::Size(157, 32);
            this->rtb_66->TabIndex = 316;
            this->rtb_66->Text = L"         TOTAL";
            this->rtb_66->Visible = false;
            //
            // rtb_75
            //
            this->rtb_75->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_75->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_75->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_75->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_75->Location = System::Drawing::Point(1524, 423);
            this->rtb_75->Name = L"rtb_75";
            this->rtb_75->ReadOnly = true;
            this->rtb_75->Size = System::Drawing::Size(134, 32);
            this->rtb_75->TabIndex = 315;
            this->rtb_75->Text = L"            -";
            this->rtb_75->Visible = false;
            //
            // rtb_85
            //
            this->rtb_85->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_85->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_85->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_85->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_85->Location = System::Drawing::Point(1664, 423);
            this->rtb_85->Name = L"rtb_85";
            this->rtb_85->ReadOnly = true;
            this->rtb_85->Size = System::Drawing::Size(129, 32);
            this->rtb_85->TabIndex = 314;
            this->rtb_85->Text = L"500";
            this->rtb_85->Visible = false;
            //
            // rtb_65
            //
            this->rtb_65->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_65->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_65->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_65->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_65->Location = System::Drawing::Point(1361, 423);
            this->rtb_65->Name = L"rtb_65";
            this->rtb_65->ReadOnly = true;
            this->rtb_65->Size = System::Drawing::Size(157, 32);
            this->rtb_65->TabIndex = 313;
            this->rtb_65->Text = L"      Ingenieria";
            this->rtb_65->Visible = false;
            //
            // rtb_74
            //
            this->rtb_74->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_74->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_74->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_74->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_74->Location = System::Drawing::Point(1524, 385);
            this->rtb_74->Name = L"rtb_74";
            this->rtb_74->ReadOnly = true;
            this->rtb_74->Size = System::Drawing::Size(134, 32);
            this->rtb_74->TabIndex = 312;
            this->rtb_74->Text = L"            -";
            this->rtb_74->Visible = false;
            //
            // rtb_84
            //
            this->rtb_84->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_84->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_84->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_84->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_84->Location = System::Drawing::Point(1664, 385);
            this->rtb_84->Name = L"rtb_84";
            this->rtb_84->ReadOnly = true;
            this->rtb_84->Size = System::Drawing::Size(129, 32);
            this->rtb_84->TabIndex = 311;
            this->rtb_84->Text = L"...";
            this->rtb_84->Visible = false;
            //
            // rtb_63
            //
            this->rtb_63->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_63->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_63->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_63->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_63->Location = System::Drawing::Point(1361, 347);
            this->rtb_63->Name = L"rtb_63";
            this->rtb_63->ReadOnly = true;
            this->rtb_63->Size = System::Drawing::Size(157, 32);
            this->rtb_63->TabIndex = 310;
            this->rtb_63->Text = L"Soporte SolarBloc";
            this->rtb_63->Visible = false;
            //
            // rtb_73
            //
            this->rtb_73->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_73->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_73->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_73->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_73->Location = System::Drawing::Point(1524, 347);
            this->rtb_73->Name = L"rtb_73";
            this->rtb_73->ReadOnly = true;
            this->rtb_73->Size = System::Drawing::Size(134, 32);
            this->rtb_73->TabIndex = 309;
            this->rtb_73->Text = L"...";
            this->rtb_73->Visible = false;
            //
            // rtb_83
            //
            this->rtb_83->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_83->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_83->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_83->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_83->Location = System::Drawing::Point(1664, 347);
            this->rtb_83->Name = L"rtb_83";
            this->rtb_83->ReadOnly = true;
            this->rtb_83->Size = System::Drawing::Size(129, 32);
            this->rtb_83->TabIndex = 308;
            this->rtb_83->Text = L"        Coste";
            this->rtb_83->Visible = false;
            //
            // rtb_64
            //
            this->rtb_64->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_64->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_64->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_64->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_64->Location = System::Drawing::Point(1361, 385);
            this->rtb_64->Name = L"rtb_64";
            this->rtb_64->ReadOnly = true;
            this->rtb_64->Size = System::Drawing::Size(157, 32);
            this->rtb_64->TabIndex = 307;
            this->rtb_64->Text = L"      Instalación";
            this->rtb_64->Visible = false;
            //
            // rtb_72
            //
            this->rtb_72->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_72->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_72->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_72->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_72->Location = System::Drawing::Point(1524, 309);
            this->rtb_72->Name = L"rtb_72";
            this->rtb_72->ReadOnly = true;
            this->rtb_72->Size = System::Drawing::Size(134, 32);
            this->rtb_72->TabIndex = 306;
            this->rtb_72->Text = L"1";
            this->rtb_72->Visible = false;
            //
            // rtb_82
            //
            this->rtb_82->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_82->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_82->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_82->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_82->Location = System::Drawing::Point(1664, 309);
            this->rtb_82->Name = L"rtb_82";
            this->rtb_82->ReadOnly = true;
            this->rtb_82->Size = System::Drawing::Size(129, 32);
            this->rtb_82->TabIndex = 305;
            this->rtb_82->Text = L"        Coste";
            this->rtb_82->Visible = false;
            //
            // rtb_62
            //
            this->rtb_62->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_62->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_62->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_62->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_62->Location = System::Drawing::Point(1361, 309);
            this->rtb_62->Name = L"rtb_62";
            this->rtb_62->ReadOnly = true;
            this->rtb_62->Size = System::Drawing::Size(157, 32);
            this->rtb_62->TabIndex = 304;
            this->rtb_62->Text = L" Inversor HUAWEI";
            this->rtb_62->Visible = false;
            //
            // rtb_71
            //
            this->rtb_71->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_71->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_71->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_71->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_71->Location = System::Drawing::Point(1524, 271);
            this->rtb_71->Name = L"rtb_71";
            this->rtb_71->ReadOnly = true;
            this->rtb_71->Size = System::Drawing::Size(134, 32);
            this->rtb_71->TabIndex = 303;
            this->rtb_71->Text = L"     Unidades";
            this->rtb_71->Visible = false;
            //
            // rtb_81
            //
            this->rtb_81->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_81->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_81->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_81->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_81->Location = System::Drawing::Point(1664, 271);
            this->rtb_81->Name = L"rtb_81";
            this->rtb_81->ReadOnly = true;
            this->rtb_81->Size = System::Drawing::Size(129, 32);
            this->rtb_81->TabIndex = 302;
            this->rtb_81->Text = L"        Coste";
            this->rtb_81->Visible = false;
            //
            // rtb_61
            //
            this->rtb_61->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_61->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_61->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_61->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_61->Location = System::Drawing::Point(1361, 271);
            this->rtb_61->Name = L"rtb_61";
            this->rtb_61->ReadOnly = true;
            this->rtb_61->Size = System::Drawing::Size(157, 32);
            this->rtb_61->TabIndex = 301;
            this->rtb_61->Text = L"        Paneles";
            this->rtb_61->Visible = false;
            //
            // rtb_70
            //
            this->rtb_70->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_70->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_70->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_70->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_70->Location = System::Drawing::Point(1524, 233);
            this->rtb_70->Name = L"rtb_70";
            this->rtb_70->ReadOnly = true;
            this->rtb_70->Size = System::Drawing::Size(134, 32);
            this->rtb_70->TabIndex = 300;
            this->rtb_70->Text = L"     Unidades";
            this->rtb_70->Visible = false;
            //
            // rtb_80
            //
            this->rtb_80->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_80->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_80->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_80->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_80->Location = System::Drawing::Point(1664, 233);
            this->rtb_80->Name = L"rtb_80";
            this->rtb_80->ReadOnly = true;
            this->rtb_80->Size = System::Drawing::Size(129, 32);
            this->rtb_80->TabIndex = 299;
            this->rtb_80->Text = L"        Coste";
            this->rtb_80->Visible = false;
            //
            // rtb_60
            //
            this->rtb_60->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_60->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_60->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_60->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_60->Location = System::Drawing::Point(1361, 233);
            this->rtb_60->Name = L"rtb_60";
            this->rtb_60->ReadOnly = true;
            this->rtb_60->Size = System::Drawing::Size(157, 32);
            this->rtb_60->TabIndex = 298;
            this->rtb_60->Text = L"Artículo o servicio";
            this->rtb_60->Visible = false;
            //
            // button1
            //
            this->button1->BackColor = System::Drawing::Color::Gray;
            this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(527, 358);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(95, 41);
            this->button1->TabIndex = 320;
            this->button1->Text = L"Ayuda";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Resultado::button1_Click);
            //
            // Resultado
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1924, 1008);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label24);
            this->Controls->Add(this->rtb_76);
            this->Controls->Add(this->rtb_86);
            this->Controls->Add(this->rtb_66);
            this->Controls->Add(this->rtb_75);
            this->Controls->Add(this->rtb_85);
            this->Controls->Add(this->rtb_65);
            this->Controls->Add(this->rtb_74);
            this->Controls->Add(this->rtb_84);
            this->Controls->Add(this->rtb_63);
            this->Controls->Add(this->rtb_73);
            this->Controls->Add(this->rtb_83);
            this->Controls->Add(this->rtb_64);
            this->Controls->Add(this->rtb_72);
            this->Controls->Add(this->rtb_82);
            this->Controls->Add(this->rtb_62);
            this->Controls->Add(this->rtb_71);
            this->Controls->Add(this->rtb_81);
            this->Controls->Add(this->rtb_61);
            this->Controls->Add(this->rtb_70);
            this->Controls->Add(this->rtb_80);
            this->Controls->Add(this->rtb_60);
            this->Controls->Add(this->label23);
            this->Controls->Add(this->label22);
            this->Controls->Add(this->label20);
            this->Controls->Add(this->label18);
            this->Controls->Add(this->label17);
            this->Controls->Add(this->label15);
            this->Controls->Add(this->label14);
            this->Controls->Add(this->label13);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->progressBar2);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->progressBar1);
            this->Controls->Add(this->richTextBox17);
            this->Controls->Add(this->rtb_52);
            this->Controls->Add(this->rtb_51);
            this->Controls->Add(this->rtb_50);
            this->Controls->Add(this->rtb_49);
            this->Controls->Add(this->rtb_48);
            this->Controls->Add(this->rtb_47);
            this->Controls->Add(this->rtb_46);
            this->Controls->Add(this->rtb_45);
            this->Controls->Add(this->rtb_44);
            this->Controls->Add(this->rtb_43);
            this->Controls->Add(this->rtb_42);
            this->Controls->Add(this->rtb_41);
            this->Controls->Add(this->rtb_40);
            this->Controls->Add(this->richTextBox16);
            this->Controls->Add(this->rtb_39);
            this->Controls->Add(this->rtb_38);
            this->Controls->Add(this->rtb_37);
            this->Controls->Add(this->rtb_36);
            this->Controls->Add(this->rtb_35);
            this->Controls->Add(this->rtb_34);
            this->Controls->Add(this->rtb_33);
            this->Controls->Add(this->rtb_32);
            this->Controls->Add(this->rtb_31);
            this->Controls->Add(this->rtb_30);
            this->Controls->Add(this->rtb_29);
            this->Controls->Add(this->rtb_28);
            this->Controls->Add(this->rtb_27);
            this->Controls->Add(this->richTextBox15);
            this->Controls->Add(this->rtb_26);
            this->Controls->Add(this->rtb_25);
            this->Controls->Add(this->rtb_24);
            this->Controls->Add(this->rtb_23);
            this->Controls->Add(this->rtb_22);
            this->Controls->Add(this->rtb_21);
            this->Controls->Add(this->rtb_20);
            this->Controls->Add(this->rtb_19);
            this->Controls->Add(this->rtb_18);
            this->Controls->Add(this->rtb_17);
            this->Controls->Add(this->rtb_16);
            this->Controls->Add(this->rtb_15);
            this->Controls->Add(this->rtb_14);
            this->Controls->Add(this->richTextBox14);
            this->Controls->Add(this->rtb_13);
            this->Controls->Add(this->rtb_12);
            this->Controls->Add(this->rtb_11);
            this->Controls->Add(this->rtb_10);
            this->Controls->Add(this->rtb_9);
            this->Controls->Add(this->rtb_8);
            this->Controls->Add(this->rtb_7);
            this->Controls->Add(this->rtb_6);
            this->Controls->Add(this->rtb_5);
            this->Controls->Add(this->rtb_4);
            this->Controls->Add(this->rtb_3);
            this->Controls->Add(this->rtb_2);
            this->Controls->Add(this->rtb_1);
            this->Controls->Add(this->richTextBox13);
            this->Controls->Add(this->richTextBox12);
            this->Controls->Add(this->richTextBox11);
            this->Controls->Add(this->richTextBox10);
            this->Controls->Add(this->richTextBox9);
            this->Controls->Add(this->richTextBox8);
            this->Controls->Add(this->richTextBox7);
            this->Controls->Add(this->richTextBox6);
            this->Controls->Add(this->richTextBox5);
            this->Controls->Add(this->richTextBox4);
            this->Controls->Add(this->richTextBox3);
            this->Controls->Add(this->richTextBox2);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->tb_Npaneles);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->tb_area);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->tb_precio);
            this->Controls->Add(this->label51);
            this->Controls->Add(this->tb_Voc);
            this->Controls->Add(this->tb_Isc);
            this->Controls->Add(this->label49);
            this->Controls->Add(this->label50);
            this->Controls->Add(this->tb_Imp);
            this->Controls->Add(this->tb_Pmp);
            this->Controls->Add(this->label46);
            this->Controls->Add(this->label47);
            this->Controls->Add(this->label48);
            this->Controls->Add(this->tb_Vmp);
            this->Controls->Add(this->label45);
            this->Controls->Add(this->label21);
            this->Controls->Add(this->tb_Eanual);
            this->Controls->Add(this->b_fich);
            this->Controls->Add(this->panel1);
            this->ForeColor = System::Drawing::SystemColors::ControlText;
            this->Name = L"Resultado";
            this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
            this->Text = L"Resultado";
            this->Load += gcnew System::EventHandler(this, &Resultado::Resultado_Load);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    #pragma endregion
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
        float datos_inv[7][2] = {
            { 2000,676.40 },        //PRECIOS ACTUALIZADOS 23/11/23 EN "AUTOSOLAR"
            { 3000,796.88 }, { 4000,973.60 }, { 5000,1057.15 }, { 6000,1232.54 }, { 10000,2820.95 }, { 20000,3151.71 }
        };
        int pos_inv;
        string nom_inv[7] = { "SUN2000_2KTL_L1","SUN2000_3KT_L1","SUN2000_4KTL_L1","SUN2000_5KTL_L1","SUN2000_6KTL_L1","SUN2000_10KTL_M1","SUN2000_2KTL_M2" };
        string error = "Error introduciendo los siguientes datos: \n", sEanual,sNp;
        bool ok = true;
        float Eanual=0;
        int Np;
        string rutaArchivo;
        float t_inv, aux = 0, Gtotalf; //Variable para no sobrecargar Irradiancia
        float Gmesf[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }, Autof[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }, Excf[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }, Emesf[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
        int Gmes[12], Auto[12], Exc[12], Emes[12], Gtotal = 0, Exctotal = 0, Autototal = 0, Etotal = 0;
        float porc_cons, porc_prod, ahorro_auto, ahorro_exc;
        std::vector<float> Irradiancia, Perf_elec, def_sup, Eauto;//Hay queutilizar la funcion push_back
        sEanual = this->toStandardString(this->tb_Eanual->Text);  //RECOGIDADE DATOS DE LOS TEXTBOX
        if (!esNumerico(sEanual)) {
            error = error + "Consumo anual \n";
            ok = false;
        }
        else {
            Eanual = stof(sEanual);
        }
        sNp = this->toStandardString(this->tb_Npaneles->Text);
        if (!esNumerico(sNp)) {
            error = error + "Número de paneles \n";
            ok = false;
        }
        else {
            Np = stof(sNp);
        }
        if (ok) {   //SE COMPRUEBA QUE SE HAYAN RECOGIDO LOS VALORES CORRECTAMENTE
            rutaArchivo = obtenerRutaRelativaArchivo();         //RECOGEMOSLOS DATOS DE LOS FICHEROS DEL PROGRAMA
            rutaArchivo = rutaArchivo + "//Irradiancia.txt";
            for (size_t i = 0; i < rutaArchivo.length(); i++)
            {
                if (rutaArchivo[i] == '\\')
                {
                    rutaArchivo.replace(i, 1, "//");
                    i++;
                }
            }
            Irradiancia = almacenarTerminosEnVector(rutaArchivo);
            rutaArchivo = obtenerRutaRelativaArchivo();
            rutaArchivo = rutaArchivo + "//perfil_elec_V2_puntos.txt";
            for (size_t i = 0; i < rutaArchivo.length(); i++)
            {
                if (rutaArchivo[i] == '\\')
                {
                    rutaArchivo.replace(i, 1, "//");
                    i++;
                }
            }
            Perf_elec = almacenarTerminosEnVector(rutaArchivo);
            if (Irradiancia.empty() || Perf_elec.empty()) { //FICHEROS AUSENTES O SIN VALORES NUMÉRICOS
                MessageBox::Show(L"No se han podido leer los ficheros de datos.\nComprueba que Irradiancia.txt y perfil_elec_V2_puntos.txt estan en la carpeta del programa y que contienen valores numericos.");
                return;
            }
            int cont = 0;
            while (Perf_elec.size() < Irradiancia.size()) {
                Perf_elec.push_back(Perf_elec[cont]);           //PREVIENE POSIBLES FALLOS CON AÑOS BISIESTOS
                cont++;
            }
            cont = 0;
            while (Perf_elec.size() > Irradiancia.size()) {
                Irradiancia.push_back(Irradiancia[cont]);       //PREVIENE POSIBLES FALLOS DEL USUARIO AL TRATAR EL FICHERO
                cont++;
            }
            for (int i = 0; i < Perf_elec.size(); i++) {
                Perf_elec[i] = Perf_elec[i] * Eanual;   //Obtenemos el consumo horario
                Irradiancia[i] = Irradiancia[i]/1000/1000 * Pm * Np * 0.8;
                  //Obtenemos la generación de los paneles horaria (SE HA AJUSTADO A 0,8 DE EFICIENCIA PARA AJUSTAR VALORES VALOR ANTERIOR 0,9)
                aux = Perf_elec[i] - Irradiancia[i];    //Se obtiene el deficit superavit horario
                def_sup.push_back(aux);
                if (Perf_elec[i]>Irradiancia[i]) {
                    Eauto.push_back(Irradiancia[i]);    //AUTOCONSUMO TODA LA PRODUCCIÓN Y HAY DEFICIT
                }
                else {
                    Eauto.push_back(Perf_elec[i]);      //AUTOCONSUMO TODA LA DEMANDA Y HAY SUPERÁVIT
                }
            }
            aux = Perf_elec.size()/12;                              // AGRUPAMOS LOS DATOS HORARIOS POR MESES (APROXIMADO POSIBLE MEJORA)
            for (int x = 0; x < 12; x++) {
                for (int j = 0; j < Perf_elec.size(); j++) {
                    if (j < aux * (x + 1) && j>aux * x) {
                        Gmesf[x] = Gmesf[x] + Irradiancia[j];   //ALMACENA LOS DATOS DE AUTOCONOSUMO Y GENERACIÓN
                        Autof[x] = Autof[x] + Eauto[j];
                        if (x < 11) {
                            Emesf[x] = Emesf[x] + Perf_elec[j];
                        }
                    }
                }
                Etotal= Etotal = Emesf[x] + Etotal;
                if (x == 11) {
                    Emesf[x] = Eanual - Etotal;     //SE HACE ESTO PARA CUADRAR LOS DATOS Y OBVIEN LA APROXIMACIÓN HECHA ANTERIORMENTE
                }
                Excf[x] = Gmesf[x] - Autof[x];
                Gmes[x] = Gmesf[x];                 //SE ALMACENAN LOS DATOSEN VALORES 'int' PARA MOSTRARLOS
                Emes[x] = Emesf[x];
                Exc[x] = Excf[x];
                Auto[x] = Autof[x];
                Gtotal = Gtotal + Gmes[x];
                Exctotal = Exctotal + Exc[x];
                Autototal = Autototal + Auto[x];
            }
            Etotal = Eanual;
            porc_cons = Autototal / Eanual*100;
            Gtotalf = Gtotal;
            porc_prod = Autototal / Gtotalf * 100;
            this->progressBar1->Visible = true;
            this->progressBar2->Visible = true;
            this->progressBar1->Increment(-anterior);   //SE INCREMENTA EL VALOR ANTERIOR EN NEGATIVO PARA REINICIAR LA BARRA Y MUESTRE LOS NUEVOS VALORES CORRECTAMENTE
            this->progressBar1->Increment(porc_cons);
            this->progressBar2->Increment(-ant);
            this->progressBar2->Increment(porc_prod);
            ant = porc_prod;
            anterior = porc_cons;
            ahorro_auto = Autototal * 0.4;
            ahorro_exc = Exctotal * 0.1;
            //SE CALCULAN LOS DATOS DE LA INVERSION EN FUNCIÖN DE LA INSTALACIÓN
            int prpaneles, prinversor, prsoporte, prinstalacion, pring, prtotal, pot_ins;
            prpaneles = Np * prpan;
            prsoporte = Np * 20;    //SE BUSCA EL PRECIO POR SOPORTE DE SOLARBLOC
            prinstalacion = Np * 350; //Aproximación en función de la experiencia trabajando
            pot_ins = Np * Pm;
            int aux_inv=0;
            bool inv_check=false;       //ASEGURA QUE SE HAYA ELEGIDO UN INVERSOR
            while (!inv_check) {
                for (int i = 0; i < 7; i++) {
                    if (pot_ins < datos_inv[i][0]+aux_inv*datos_inv[6][0] && !inv_check) {
                        pos_inv = i;
                        inv_check = true;
                    }
                }
                if (!inv_check) aux_inv++;
            }
            prinversor = datos_inv[pos_inv][1] + aux_inv * datos_inv[6][1];
            if (pot_ins > 10000) pring = 1000;
            else pring = 500;
            prtotal = prpaneles + prsoporte + prinstalacion + pring;
            //SE CALCULA EL TIEMPO DE RECUPERACIÓN DE LA INVERSIÓN
            t_inv = prtotal / (ahorro_auto + ahorro_exc);
            this->rtb_1->Visible = true;
            rtb_1->Text = gcnew System::String(to_string(Emes[0]).c_str());
            this->rtb_2->Visible = true;
            rtb_2->Text = gcnew System::String(to_string(Emes[1]).c_str());
            this->rtb_3->Visible = true;
            rtb_3->Text = gcnew System::String(to_string(Emes[2]).c_str());
            this->rtb_4->Visible = true;
            rtb_4->Text = gcnew System::String(to_string(Emes[3]).c_str());
            this->rtb_5->Visible = true;
            rtb_5->Text = gcnew System::String(to_string(Emes[4]).c_str());
            this->rtb_6->Visible = true;
            rtb_6->Text = gcnew System::String(to_string(Emes[5]).c_str());
            this->rtb_7->Visible = true;
            rtb_7->Text = gcnew System::String(to_string(Emes[6]).c_str());
            this->rtb_8->Visible = true;
            rtb_8->Text = gcnew System::String(to_string(Emes[7]).c_str());
            this->rtb_9->Visible = true;
            rtb_9->Text = gcnew System::String(to_string(Emes[8]).c_str());
            this->rtb_10->Visible = true;
            rtb_10->Text = gcnew System::String(to_string(Emes[9]).c_str());
            this->rtb_11->Visible = true;
            rtb_11->Text = gcnew System::String(to_string(Emes[10]).c_str());
            this->rtb_12->Visible = true;
            rtb_12->Text = gcnew System::String(to_string(Emes[11]).c_str());
            this->rtb_13->Visible = true;
            rtb_13->Text = gcnew System::String(to_string(Etotal).c_str());
            this->rtb_14->Visible = true;
            rtb_14->Text = gcnew System::String(to_string(Gmes[0]).c_str());
            this->rtb_15->Visible = true;
            rtb_15->Text = gcnew System::String(to_string(Gmes[1]).c_str());
            this->rtb_16->Visible = true;
            rtb_16->Text = gcnew System::String(to_string(Gmes[2]).c_str());
            this->rtb_17->Visible = true;
            rtb_17->Text = gcnew System::String(to_string(Gmes[3]).c_str());
            this->rtb_18->Visible = true;
            rtb_18->Text = gcnew System::String(to_string(Gmes[4]).c_str());
            this->rtb_19->Visible = true;
            rtb_19->Text = gcnew System::String(to_string(Gmes[5]).c_str());
            this->rtb_20->Visible = true;
            rtb_20->Text = gcnew System::String(to_string(Gmes[6]).c_str());
            this->rtb_21->Visible = true;
            rtb_21->Text = gcnew System::String(to_string(Gmes[7]).c_str());
            this->rtb_22->Visible = true;
            rtb_22->Text = gcnew System::String(to_string(Gmes[8]).c_str());
            this->rtb_23->Visible = true;
            rtb_23->Text = gcnew System::String(to_string(Gmes[9]).c_str());
            this->rtb_24->Visible = true;
            rtb_24->Text = gcnew System::String(to_string(Gmes[10]).c_str());
            this->rtb_25->Visible = true;
            rtb_25->Text = gcnew System::String(to_string(Gmes[11]).c_str());
            this->rtb_26->Visible = true;
            rtb_26->Text = gcnew System::String(to_string(Gtotal).c_str());
            this->rtb_27->Visible = true;
            rtb_27->Text = gcnew System::String(to_string(Exc[0]).c_str());
            this->rtb_28->Visible = true;
            rtb_28->Text = gcnew System::String(to_string(Exc[1]).c_str());
            this->rtb_29->Visible = true;
            rtb_29->Text = gcnew System::String(to_string(Exc[2]).c_str());
            this->rtb_30->Visible = true;
            rtb_30->Text = gcnew System::String(to_string(Exc[3]).c_str());
            this->rtb_31->Visible = true;
            rtb_31->Text = gcnew System::String(to_string(Exc[4]).c_str());
            this->rtb_32->Visible = true;
            rtb_32->Text = gcnew System::String(to_string(Exc[5]).c_str());
            this->rtb_33->Visible = true;
            rtb_33->Text = gcnew System::String(to_string(Exc[6]).c_str());
            this->rtb_34->Visible = true;
            rtb_34->Text = gcnew System::String(to_string(Exc[7]).c_str());
            this->rtb_35->Visible = true;
            rtb_35->Text = gcnew System::String(to_string(Exc[8]).c_str());
            this->rtb_36->Visible = true;
            rtb_36->Text = gcnew System::String(to_string(Exc[9]).c_str());
            this->rtb_37->Visible = true;
            rtb_37->Text = gcnew System::String(to_string(Exc[10]).c_str());
            this->rtb_38->Visible = true;
            rtb_38->Text = gcnew System::String(to_string(Exc[11]).c_str());
            this->rtb_39->Visible = true;
            rtb_39->Text = gcnew System::String(to_string(Exctotal).c_str());
            this->rtb_40->Visible = true;
            rtb_40->Text = gcnew System::String(to_string(Auto[0]).c_str());
            this->rtb_41->Visible = true;
            rtb_41->Text = gcnew System::String(to_string(Auto[1]).c_str());
            this->rtb_42->Visible = true;
            rtb_42->Text = gcnew System::String(to_string(Auto[2]).c_str());
            this->rtb_43->Visible = true;
            rtb_43->Text = gcnew System::String(to_string(Auto[3]).c_str());
            this->rtb_44->Visible = true;
            rtb_44->Text = gcnew System::String(to_string(Auto[4]).c_str());
            this->rtb_45->Visible = true;
            rtb_45->Text = gcnew System::String(to_string(Auto[5]).c_str());
            this->rtb_46->Visible = true;
            rtb_46->Text = gcnew System::String(to_string(Auto[6]).c_str());
            this->rtb_47->Visible = true;
            rtb_47->Text = gcnew System::String(to_string(Auto[7]).c_str());
            this->rtb_48->Visible = true;
            rtb_48->Text = gcnew System::String(to_string(Auto[8]).c_str());
            this->rtb_49->Visible = true;
            rtb_49->Text = gcnew System::String(to_string(Auto[9]).c_str());
            this->rtb_50->Visible = true;
            rtb_50->Text = gcnew System::String(to_string(Auto[10]).c_str());
            this->rtb_51->Visible = true;
            rtb_51->Text = gcnew System::String(to_string(Auto[11]).c_str());
            this->rtb_52->Visible = true;
            rtb_52->Text = gcnew System::String(to_string(Autototal).c_str());
            this->richTextBox1->Visible = true;
            this->richTextBox2->Visible = true;
            this->richTextBox3->Visible = true;
            this->richTextBox4->Visible = true;
            this->richTextBox5->Visible = true;
            this->richTextBox6->Visible = true;
            this->richTextBox7->Visible = true;
            this->richTextBox8->Visible = true;
            this->richTextBox9->Visible = true;
            this->richTextBox10->Visible = true;
            this->richTextBox11->Visible = true;
            this->richTextBox12->Visible = true;
            this->richTextBox13->Visible = true;
            this->richTextBox14->Visible = true;
            this->richTextBox15->Visible = true;
            this->richTextBox16->Visible = true;
            this->richTextBox17->Visible = true;
            this->label3->Visible = true;
            this->label4->Visible = true;
            this->label5->Visible = true;
            this->label6->Visible = true;
            this->label9->Visible = true;
            this->label10->Visible = true;
            this->label11->Visible = true;
            this->label12->Visible = true;
            this->label13->Visible = true;
            this->label14->Visible = true;
            this->label15->Visible = true;
            this->label17->Visible = true;
            this->label18->Visible = true;
            this->label20->Visible = true;
            this->label22->Visible = true;
            this->label23->Visible = true;
            label6->Text = gcnew System::String(to_string(porc_cons).c_str());
            label9->Text = gcnew System::String(to_string(porc_prod).c_str());
            label14->Text = gcnew System::String(to_string(ahorro_auto).c_str());
            label15->Text = gcnew System::String(to_string(ahorro_exc).c_str());
            label22->Text = gcnew System::String(to_string(t_inv).c_str());
            //SE MUESTRAN LOS RESULTADOS DE LA INVERSION this->label24->Visible = true;
            this->rtb_60->Visible = true;
            this->rtb_61->Visible = true;
            this->rtb_62->Visible = true;
            this->rtb_63->Visible = true;
            this->rtb_64->Visible = true;
            this->rtb_65->Visible = true;
            this->rtb_66->Visible = true;
            this->rtb_70->Visible = true;
            this->rtb_71->Visible = true;
            rtb_71->Text = gcnew System::String(to_string(Np).c_str());
            this->rtb_72->Visible = true;
            this->rtb_73->Visible = true;
            rtb_73->Text = gcnew System::String(to_string(Np).c_str());
            this->rtb_74->Visible = true;
            this->rtb_75->Visible = true;
            this->rtb_76->Visible = true;
            this->rtb_80->Visible = true;
            this->rtb_81->Visible = true;
            rtb_81->Text = gcnew System::String(to_string(prpaneles).c_str());
            this->rtb_82->Visible = true;
            rtb_82->Text = gcnew System::String(to_string(prinversor).c_str());
            this->rtb_83->Visible = true;
            rtb_83->Text = gcnew System::String(to_string(prsoporte).c_str());
            this->rtb_84->Visible = true;
            rtb_84->Text = gcnew System::String(to_string(prinstalacion).c_str());
            this->rtb_85->Visible = true;
            rtb_85->Text = gcnew System::String(to_string(pring).c_str());
            this->rtb_86->Visible = true;
            rtb_86->Text = gcnew System::String(to_string(prtotal).c_str());
        }
        else MessageBox::Show(this->toSystemString(error));
    }
    std::string obtenerRutaRelativaArchivo()
    {
        String^ rutaEnsamblado = Assembly::GetExecutingAssembly()->Location;
        String^ rutaDirectorio = Path::GetDirectoryName(rutaEnsamblado);
        std::string rutaRelativa = toStandardString(rutaDirectorio);
        return rutaRelativa;
    }
    // Interpreta una línea de texto como un valor numérico. Devuelve false si la línea no es un número
    // (cabeceras, notas, líneas vacías...). Admite coma o punto decimal y las filas de datos de PVGIS
    // ("AAAAMMDD:HHMM,G(i),..."), de las que se toma la primera columna de datos, G(i).
    bool leerValorLinea(const std::string& linea, float& valor)
    {
        std::string s = linea;
        if (s.size() > 14 && s[8] == ':' && s[13] == ',') {     //FILA DE DATOS HORARIOS DE PVGIS
            bool fecha = true;
            for (int k = 0; k < 13; k++) {
                if (k != 8 && !isdigit((unsigned char)s[k])) fecha = false;
            }
            if (fecha) {
                size_t fin = s.find(',', 14);
                s = s.substr(14, fin == std::string::npos ? std::string::npos : fin - 14);
            }
        }
        size_t ini = s.find_first_not_of(" \t");
        if (ini == std::string::npos) return false;
        s = s.substr(ini, s.find_last_not_of(" \t") - ini + 1);
        int comas = 0;
        for (size_t k = 0; k < s.length(); k++) {
            if (s[k] == ',') { comas++; s[k] = '.'; }           //LA COMA DECIMAL SE CAMBIA POR PUNTO
        }
        if (comas > 1) return false;
        char* resto = nullptr;
        double d = strtod(s.c_str(), &resto);
        if (resto == s.c_str() || *resto != '\0') return false;
        if (!(d > -1e30 && d < 1e30)) return false;
        valor = (float)d;
        return true;
    }
    // Lee un fichero con un valor por línea (separadores \r, \n o \r\n). Las líneas no numéricas se ignoran,
    // de modo que sirve tanto una lista simple de números como el CSV horario descargado de PVGIS.
    std::vector<float> almacenarTerminosEnVector(std::string& rutaArchivo)
    {
        std::vector<float> termf;
        std::ifstream archivo(rutaArchivo, std::ios::binary);
        if (!archivo.is_open()) return termf;
        std::ostringstream ss;
        ss << archivo.rdbuf();
        archivo.close();
        std::string contenido = ss.str();
        contenido.push_back('\n');                              //PARA PROCESAR TAMBIÉN LA ÚLTIMA LÍNEA
        std::string linea;
        for (size_t i = 0; i < contenido.length(); i++) {
            char c = contenido[i];
            if (c != '\r' && c != '\n') {
                linea.push_back(c);
                continue;
            }
            float v;
            if (!linea.empty() && leerValorLinea(linea, v)) termf.push_back(v);
            linea.clear();
        }
        return termf;
    }
    private: static String^ toSystemString(string str) {
           return gcnew String(str.c_str());
       }
    private: static string toStandardString(System::String^ string)
        {
            using System::Runtime::InteropServices::Marshal;
            System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
            char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
            std::string returnString(charPointer, string->Length);
            Marshal::FreeHGlobal(pointer);
            return returnString;
        }
    private: bool esNumerico(string texto) {
            if (texto.length() == 0) {
                return false;
            }
            bool decimalEncontrado = false;
            bool negativoEncontrado = false;
            for (char c : texto) {
                if (isdigit(c)) {
                    continue;
                }
                else if ((c == '.' || c == ',') && !decimalEncontrado) {
                    decimalEncontrado = true;
                    continue;
                }
                else if (c == '-' && !negativoEncontrado) {
                    negativoEncontrado = true;
                    continue;
                }
                else {
                    return false;
                }
            }
            return true;
        }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        string sPmp, sVoc, sIsc, sVmp, sImp, sprecio, sarea, error = "Error introduciendo:\n";
        bool ok = true;
        sVmp = this->toStandardString(this->tb_Vmp->Text);
        if (!esNumerico(sVmp)) {
            error = error + "Vmp \n";
            ok = false;
        }
        else {
            Vm = stof(sVmp);
        }
        sImp = this->toStandardString(this->tb_Imp->Text);
        if (!esNumerico(sImp)) {
            error = error + "Imp \n";
            ok = false;
        }
        else {
            Im = stof(sImp);
        }
        sPmp = this->toStandardString(this->tb_Pmp->Text);
        if (!esNumerico(sPmp)) {
            error = error + "Potencia \n";
            ok = false;
        }
        else {
            Pm = stof(sPmp);
        }
        sVoc = this->toStandardString(this->tb_Voc->Text);
        if (!esNumerico(sVoc)) {
            error = error + "Voc \n";
            ok = false;
        }
        else {
            Voc = stof(sVoc);
        }
        sIsc = this->toStandardString(this->tb_Isc->Text);
        if (!esNumerico(sIsc)) {
            error = error + "Isc \n";
            ok = false;
        }
        else {
            Isc = stof(sIsc);
        }
        sprecio = this->toStandardString(this->tb_precio->Text);
        if (!esNumerico(sprecio)) {
            error = error + "Precio \n";
            ok = false;
        }
        else {
            prpan = stof(sprecio);
        }
        sarea = this->toStandardString(this->tb_area->Text);
        if (!esNumerico(sarea)) {
            error = error + "Area \n";
            ok = false;
        }
        else {
            prpan = stof(sarea);
        }
        if (ok == false) {
            MessageBox::Show(this->toSystemString(error));
        }
        else MessageBox::Show(L"Valores actualizados");
    }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show(L"Es necesario introucir el fichero con los datos de Irradiancia horaria para la ubicación deseada. \nPara mas información consulta la guía de uso. ");
}
private: System::Void Resultado_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
