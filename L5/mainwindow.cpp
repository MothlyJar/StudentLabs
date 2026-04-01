<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>782</width>
    <height>621</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <widget class="QPushButton" name="Load_pB">
    <property name="geometry">
     <rect>
      <x>290</x>
      <y>500</y>
      <width>181</width>
      <height>29</height>
     </rect>
    </property>
    <property name="styleSheet">
     <string notr="true">background: rgb(12, 190, 255);</string>
    </property>
    <property name="text">
     <string>Загрузить</string>
    </property>
   </widget>
   <widget class="QFrame" name="OuterFrame">
    <property name="geometry">
     <rect>
      <x>60</x>
      <y>40</y>
      <width>661</width>
      <height>441</height>
     </rect>
    </property>
    <property name="frameShape">
     <enum>QFrame::Shape::StyledPanel</enum>
    </property>
    <property name="frameShadow">
     <enum>QFrame::Shadow::Raised</enum>
    </property>
    <widget class="QTreeWidget" name="treeWidget">
     <property name="geometry">
      <rect>
       <x>30</x>
       <y>20</y>
       <width>601</width>
       <height>391</height>
      </rect>
     </property>
     <property name="font">
      <font>
       <pointsize>16</pointsize>
      </font>
     </property>
     <property name="columnCount">
      <number>5</number>
     </property>
     <attribute name="headerVisible">
      <bool>false</bool>
     </attribute>
     <column>
      <property name="text">
       <string notr="true">1</string>
      </property>
     </column>
     <column>
      <property name="text">
       <string notr="true">2</string>
      </property>
     </column>
     <column>
      <property name="text">
       <string notr="true">3</string>
      </property>
     </column>
     <column>
      <property name="text">
       <string notr="true">4</string>
      </property>
     </column>
     <column>
      <property name="text">
       <string notr="true">5</string>
      </property>
     </column>
    </widget>
   </widget>
   <widget class="QLabel" name="exceptions">
    <property name="geometry">
     <rect>
      <x>60</x>
      <y>10</y>
      <width>371</width>
      <height>20</height>
     </rect>
    </property>
    <property name="text">
     <string/>
    </property>
   </widget>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
 </widget>
 <resources/>
 <connections/>
</ui>
