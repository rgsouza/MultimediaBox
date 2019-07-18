
import javax.swing.*;
import javax.imageio.ImageIO;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.GridLayout;

/**
 * 
 * @author Rayanne Souza 
 * @version 1 
 * @since 2015-11-03
 * @brief Cette classe répresente une interface avec le client.
 * Cette interface permettre ajouter des films,videos et photos multimedia dans une liste
 * afin de jouer ces elements, afficher les informations, chercher un fichier multimedia et 
 * supprimer des elements. 
 * @see Client
 */ 
public class MainWindow extends JFrame{
	JButton close, button_info, button_search;
	JTextArea text;
	JScrollPane scroll;
	JMenuBar menuBar;
	JMenu menu;
	JPanel panneau;
	JToolBar toolBar;
	JTextField field;
	ActionMenu filesAction;
	ActionMenu playAction;
	ActionMenu button_closeAction;
	ActionMenu addPhotoAction, addVideoAction, addFilmAction, deleteFileAction;
	
	private static final long serialVersionUID = 1L;
	
	/// Crée un MainWindow et fait appel à la main du client.
	public static void main(String[] args) {
		MainWindow window = new MainWindow();
		
		
		window.setDefaultCloseOperation(EXIT_ON_CLOSE);
		window.pack();
		window.setVisible(true);
		window.setSize(800, 500);
		window.setLocationRelativeTo(null);
		
		//Inclusion de la main du client.
		Client.main(args);

		
		
		
	}
	
	
	/**
	 * Ce méthode crée la fenêtre principal dont les composants sont:
	 * - Menu et toolBar: avec des boutton close, show all files, add film, add photo, add video, delete et play un multimedia file.
	 * - Des bouttons localisés au sud de la fenêtre: close, info (pour afficher les information sur un fichier )
	 * et Search pour rechercher des éléments dans la bibliothèque multimedia.
	 */
	public MainWindow(){
	    panneau = new JPanel();
		
	    
	    //Ajoute les bouttons close, info et search au sud de la fenêtre.        
        panneau.add( close = new JButton("Close", new ImageIcon("close.png")), BorderLayout.AFTER_LAST_LINE);
		panneau.add( button_info = new JButton("Info", new ImageIcon("info.png") ), BorderLayout.AFTER_LAST_LINE );
		panneau.add( button_search = new JButton("Search", new ImageIcon( "search.png")), BorderLayout.AFTER_LAST_LINE );
		
		
		//Ajoute un layout au panneau.
		this.add(panneau, BorderLayout.AFTER_LAST_LINE) ;
		
		//Ajoute un TextArea et un Scroll au panneau.
		this.add(text = new JTextArea(50,20), BorderLayout.CENTER);
		this.add(scroll = new JScrollPane(text), BorderLayout.CENTER);
		
		//Crée des actions show, play, close, addPhoto, addVideo, addFilm et delete a file.
		filesAction = new ActionMenu("Show Files", new ImageIcon("show.png"));
		playAction = new ActionMenu("Play", new ImageIcon("play.png"));
		button_closeAction = new ActionMenu("Close", new ImageIcon("close.png"));
		addPhotoAction = new ActionMenu("Add Photo",new ImageIcon("photo.png"));
		addVideoAction = new ActionMenu("Add Video", new ImageIcon("video.png"));
		addFilmAction = new ActionMenu("Add Film", new ImageIcon("film.png"));
		deleteFileAction = new ActionMenu("Delete File", new ImageIcon("delete.png"));
		
		//Crée un menu
		menu = new JMenu("Menu");
		menuBar = new JMenuBar();
		
		//Crée un toolBar
		toolBar = new JToolBar();
		
		//Ajoute les bouttons au menu
		
		menu.add(addPhotoAction);
		menu.add(addVideoAction);
		menu.add(addFilmAction);
		menu.add(filesAction);
		menu.add(playAction);
		menu.add(deleteFileAction);
		menu.add(button_closeAction);
		
		
		//Crée les toolbar boutons en utilisant les mêmes actions du menuBar
		toolBar.add(new JButton (addPhotoAction));
		toolBar.add(new JButton(addVideoAction));
		toolBar.add( new JButton(addFilmAction));
		toolBar.add(new JButton(filesAction));
		toolBar.add(new JButton( playAction));
		toolBar.add(new JButton(deleteFileAction));
		toolBar.add(new JButton(button_closeAction));
		
		menuBar.add(menu);
		
		//Ajoute le menu à la fenêtre principal.
		this.setJMenuBar(menuBar);
		
		//Ajoute le toolBar à la fenêtre principal.
		this.add(toolBar, BorderLayout.NORTH);
		
		this.setTitle("MultimediaBox");
		this.setResizable(true);
		
		
		//Ajoute actions aux buttons close , info et search.
		close.addActionListener(new CloseListener());
		button_info.addActionListener(new InformationMultimediaFile());
		button_search.addActionListener(new SearchMultimediaFile() );
	}
	
	
	/**
	* @author Rayanne Souza
	* @version 1 
	* @since 2015-11-03
	* @brief Cette classe répresente l'action de finaliser le programme au moment que le boutton close est appuyé.
	*/
	class CloseListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.exit(0);
		}
	}
	
	
	/**
	 * @author Rayanne Souza
	 * @version 1 
	 * @since 2015-11-03
	 * @brief Cette classe répresente l'action d'appuyé un boutton d'information.
	 * Au moment qu'il est appuyé une nouvelle fenêtre avec un champ de texte est créée 
	 * afin de permettre l'écriture du nom du fichier multimidia.
	 * Après cette écriture  et l'appui du boutton ok une actionListener est appelée 
	 * pour chercher ce fichier multimedia et l'afficher.    
	*/
	class InformationMultimediaFile implements ActionListener{
		public void actionPerformed(ActionEvent e){
			
			//Crée une nouvelle fenêtre.
			final JFrame info =  new JFrame();
			JButton ok;
			final JTextField field;
			JPanel panel1 = new JPanel();
			
			//Set layout for panel.
			panel1.setLayout(new BoxLayout(panel1,BoxLayout.LINE_AXIS ));
			
			//Ajoute une label et un champ de texte.
			panel1.add(new JLabel("File name:"));
			panel1.add(field = new JTextField(30));
			
			JPanel panel2 = new JPanel();
			panel2.setLayout(new BoxLayout(panel2,BoxLayout.LINE_AXIS ));
			
			//Ajoute le boutthon ok
			panel2.add(ok = new JButton("OK"));
			
			//L'action du boutton est afficher sur la zone de texte les informations
			// du fichier cherché.
			ok.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					
					String name = field.getText();
					
					if(name.length() != 0)
					{
						// Envoie la request 2 afin d'entrer à l'option 2(2 - Information about a multimedia file)
						// du server.
						Client.sendRequest("2");
						
						//Prend la reponse du server
						String reponse = Client.sendRequest(field.getText()) + "\n" ;
						text.setText(null);
						
						//Affiche la reponse qui sont les information, sur la zone de texte.
						text.append(reponse);
					    
						// Envoie l'option "return" du server afin de returner au menu principal.
						Client.sendRequest("return");
						
						// Ferme la fenêtre info.
						info.dispose();
				  }
					else
						JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any field is empty.","Error Message",JOptionPane.ERROR_MESSAGE);
				}
			});
			
			JPanel panel3 = new JPanel();
			panel3.setLayout(new BoxLayout(panel3, BoxLayout.PAGE_AXIS));
			panel3.add(panel1);
			panel3.add(panel2);
			
			//Configuration de la fenêtre d'information
			info.setTitle("Information About a Multimedia File");
			info.setLocationRelativeTo(null);
			info.getContentPane().add(panel3);
			info.pack();
			info.setVisible(true);
			
		
		}
	}
	
	
	/**
	 * 
	 * @author Rayanne Souza
	 * @version 1 
	 * @since 2015-11-10
	 *
	 * @brief Cette classe répresente l'action d'appuyé un boutton de search.
	 * Au moment qu'il est appuyé une nouvelle fenêtre avec un champ de texte est créée 
	 * afin de permettre l'écriture du nom du fichier multimidia.
	 * Après cette écriture et l'appui du boutton search une actionListener est appelée 
	 * pour chercher ce fichier multimedia et afficher ses informations.    
	 */
	class SearchMultimediaFile implements ActionListener{
		public void actionPerformed(ActionEvent e){
			
			
			//Crée une nouvelle fenêtre.
			final JFrame searchMultimedia =  new JFrame();
			
			JButton search;
			final JTextField field;
			JPanel panel1 = new JPanel();
			
			//Set layout for panel.
			panel1.setLayout(new BoxLayout(panel1,BoxLayout.LINE_AXIS ));
			
			//Ajoute une label et un champ de texte.
			panel1.add(new JLabel("File name:"));
			panel1.add(field = new JTextField(30));
			
			JPanel panel2 = new JPanel();
			panel2.setLayout(new BoxLayout(panel2,BoxLayout.LINE_AXIS ));
			
			//Crée et ajoute le boutthon Search
			panel2.add(search = new JButton("Search"));
			
			
			//L'action du boutton est afficher sur la zone de texte les informations
			// du fichier cherché.
			search.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					
					String name = field.getText();
					
					if(name.length() != 0)
					{
					// Envoie la request 3 afin d'entrer à l'option 3(3 - Search a multimedia file)
					// du server.
					Client.sendRequest("3");
					
					//Prend la reponse du server
					String reponse = Client.sendRequest(field.getText()) + "\n" ;
					text.setText(null);
					
					//Affiche la reponse qui sont les information, sur la zone de texte.
					text.append(reponse);
					
					// Envoie l'option "return" du server afin de returner au menu principal.
					Client.sendRequest("return");
					
					// Ferme la fanêtre search.
					searchMultimedia.dispose();
					}
					else
						JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any field is empty.","Error Message",JOptionPane.ERROR_MESSAGE);
				}
			});
			
			JPanel panel3 = new JPanel();
			panel3.setLayout(new BoxLayout(panel3, BoxLayout.PAGE_AXIS));
			panel3.add(panel1);
			panel3.add(panel2);
			
			//Configuration de la fenêtre Search a multimedia file.
			searchMultimedia.setTitle("Search a multimedia file");
			searchMultimedia.setLocationRelativeTo(null);
			
			searchMultimedia.getContentPane().add(panel3);
			searchMultimedia.pack();
			searchMultimedia.setVisible(true);
			
			
			
			
		}
	}
	
	
	/**
	 * 
	 * @author Rayanne Souza
	 * @version 1 
	 * @since 2015-11-12
	 * @brief Cette classe est une abstract action utilisée afin de permettre l'inclusion d'une Action simultanément   
	 * dans le JMenu et le JToolBar.
	 * Les actions sont:
	 * - Close : ferme la fenêtre principal.
	 * - Paly : Joue un fichier multimedia.
	 * - Add photo : Ajoute une photo à liste de fichiers multimedia avec les informations suivantes:
	 * 				 Nom, chemin d'accès à un fichier, longueur et largeur d'une photo.
	 * - Add video : Ajoute une video à liste de fichiers multimedia avec les informations suivantes:
	 * 				 Nom, chemin d'accès à un fichier et duration en secondes de la video.
	 * - Add film :  Ajoute un film à liste de fichiers multimedia avec les informations suivantes:
	 *       		 Nom, chemin d'accès à un fichier, duration en secondes du film et un nombre de chapitres.
	 * - Delete a file : Supprime un fichier multimedia de la liste à partir d'un nom multimedia fourni. 
	 */
	 
	class ActionMenu extends AbstractAction{
		
		/// Constructor: il construit une Action afin de permettre l'inclure simultanément   
		/// dans le menu et le toolbar.
		/// @param texte represente le nom du composant.
		public ActionMenu(String texte, ImageIcon icon ){
			super(texte);
			
			 putValue(SMALL_ICON, icon);
		}
		
		public void actionPerformed(ActionEvent e){
			 
				
				//C'est l'action de finaliser le programme au moment que le boutton close est appuyé.
				if(e.getActionCommand() == "Close")
				{	System.exit(0);
					
				}
				
				//C'est l'action de afficher tous les fichiers qui existe dans la bibliothèque multimedia. 
				else if( e.getActionCommand() == "Show Files")
				{	
					String reponse = "List of all files:\n";
					reponse += Client.sendRequest("show") + "\n";
					
					// Affiche la reponse sur textArea.
					text.append(reponse);					
					
				}
				
				
				// C'est l'action de jouer un fichier multimedia.
				// Au moment que l'option play est sélectionné une nouvelle fenêtre avec un champ de texte est créée 
				// afin de permettre l'écriture du nom du fichier multimidia.
				// Après cette écriture et l'appui du boutton ok, une actionListener est appelée au pour 
				// chercher ce fichier multimedia et le jouer.    
				else if(e.getActionCommand() == "Play")
				{
					
					//Crée une nouvelle fenêtre.
					final JFrame play =  new JFrame();
					JButton ok;
					final JTextField field;
					JPanel panel1 = new JPanel();
					
					//Set layout for panel.
					panel1.setLayout(new BoxLayout(panel1,BoxLayout.LINE_AXIS ));
					
					//Ajoute une label et un champ de texte.
					panel1.add(new JLabel("File name:"));
					panel1.add(field = new JTextField(30));
					
					JPanel panel2 = new JPanel();
					panel2.setLayout(new BoxLayout(panel2,BoxLayout.LINE_AXIS ));
					
					//Crée et ajoute le bouthon OK.
					panel2.add(ok = new JButton("OK"));
					
					
					//L'action du boutton est jouer le fichier multimedia et afficher la
					//reponse du server.
					ok.addActionListener(new ActionListener(){
						public void actionPerformed(ActionEvent e){
							
							String name = field.getText();
							
							if(name.length() != 0)
							{
								// Envoie la request 1 afin d'entrer à l'option 1(1 - Play a multimedia file)
								// du server.
								Client.sendRequest("1");
								
								//Prend la reponse du server.
								String response = Client.sendRequest(field.getText()) + "\n" ;
								text.setText(null);
								
								//Affiche la reponse qui sont les information, sur la zone de texte.
								text.append(response);
								
								// Envoie l'option "return" du server afin de returner au menu principal.
								Client.sendRequest("return");
								
								// Ferme la fenêtre play.
								play.dispose();
								
							}
							else
								JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any field is empty.","Error Message",JOptionPane.ERROR_MESSAGE);
							
						}
					});
					
					JPanel panel3 = new JPanel();
					panel3.setLayout(new BoxLayout(panel3, BoxLayout.PAGE_AXIS));
					panel3.add(panel1);
					panel3.add(panel2);
					
					//Configuration de la fenêtre Play a multimedia file.
					play.setTitle("Play Multimedia File");
					play.setLocationRelativeTo(null);
					
					play.getContentPane().add(panel3);
					play.pack();
					play.setVisible(true);
					
				
					
				}
				
				else if ( e.getActionCommand() == "Add Photo")
				{
					//Crée une nouvelle fenêtre.
					final JFrame addPhoto =  new JFrame();
					JButton add;
					final JTextField fieldName;
					final JTextField fieldPath;
					final JTextField fieldHeight;
					final JTextField fieldWidth;
					
					JPanel panelName = new JPanel();
											
					//Ajoute une label et un champ de texte pour nom du fichier.
					panelName.add(new JLabel(" File name:"));
					panelName.add( fieldName = new JTextField(30));
				
				    
				    
					JPanel panelPath = new JPanel();
					
					//Ajoute une label et un champ de texte pour chemin d'accès à un fichier.
					panelPath.add(new JLabel("Path name:"));
					panelPath.add( fieldPath = new JTextField(30));
			
					
					JPanel panelHeight = new JPanel();
					
					//Ajoute une label et un champ de texte pour largeur d'une photo.
					panelHeight.add(new JLabel("       Height:"));
					panelHeight.add( fieldHeight = new JTextField(30));
					
					JPanel panelWidth = new JPanel();
					
					//Ajoute une label et un champ de texte pour longueur d'une photo.
					panelWidth.add(new JLabel("       Widtht:"));
					panelWidth.add( fieldWidth = new JTextField(30));
					
					
					
					JPanel panelok = new JPanel();
					panelok.setLayout(new BoxLayout(panelok,BoxLayout.LINE_AXIS ));
					
					//Crée et ajoute le bouthon OK.
					panelok.add(add = new JButton("OK"));
					
					
					// L'action du boutton est envoyer au server les information qu'il y a dans chaque
					// champ de texte afin de ajouter une photo à liste de fichiers multimedia.
					// Au-délà, il envoie la message au client: "The photo was added" si tout se passe bien ou
					// "Error! The photo was not added" cas contraire.
					add.addActionListener(new ActionListener(){
						public void actionPerformed(ActionEvent e){
							
							
							String name = fieldName.getText();
							String pathName = fieldPath.getText();
							String height = fieldHeight.getText();
							String width = fieldWidth.getText();
							
							if(name.length() == 0 || pathName.length() == 0 || height.length() == 0 || width.length() == 0 )
								JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any fields are empty.","Error Message",JOptionPane.ERROR_MESSAGE);
							
							else
							{
								// Envoie la request 4 afin d'entrer à l'option 4(4 - Add a photo)
								// du server.
								Client.sendRequest("4");
							    
								// Preparation de la request à être envoyée.
								String request = fieldName.getText() + ";" + fieldPath.getText() + ";" + fieldHeight.getText() + ";" + fieldWidth.getText();
								
								//Prend la reponse du server.
								String response = Client.sendRequest(request) + "\n" ;
								
								// Envoie la message au client.
								JOptionPane.showMessageDialog(new JFrame(),response);
								
								// Envoie l'option "return" du server afin de returner au menu principal.
								Client.sendRequest("return");
								
								// Ferme la fenêtre add photo.
								addPhoto.dispose();
							}
						}
					});
					
					JPanel panel = new JPanel();
					panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
					panel.add(panelName);
					panel.add(panelPath);
					panel.add(panelHeight);
					panel.add(panelWidth);
					panel.add(panelok);
					
					//Configuration de la fenêtre add photo.
					addPhoto.setTitle("Add Photo");
					addPhoto.setLocationRelativeTo(null);
					
					addPhoto.getContentPane().add(panel);
					addPhoto.pack();
					addPhoto.setVisible(true);
				}
				
				
				else if ( e.getActionCommand() == "Add Video")
				{
					//Crée une nouvelle fenêtre.
					final JFrame addVideo =  new JFrame();
					JButton add;
					final JTextField fieldName;
					final JTextField fieldPath;
					final JTextField fieldDuration;
				
					
					JPanel panelName = new JPanel();
						
					//Ajoute une label et un champ de texte pour nom du fichier.
					panelName.add(new JLabel("File name:"));
					panelName.add( fieldName = new JTextField(30));
					
				    
					JPanel panelPath = new JPanel();
					
					//Ajoute une label et un champ de texte pour chemin d'accès à un fichier video.
					panelPath.add(new JLabel("Path name:"));
					panelPath.add( fieldPath = new JTextField(30));
					
					
					JPanel panelDuration = new JPanel();
					
					//Ajoute une label et un champ de texte pour la durée integrale d'une video .
					panelDuration.add(new JLabel("  Duration:"));
					panelDuration.add( fieldDuration = new JTextField(30));
	
					
					
					JPanel panelok = new JPanel();
					panelok.setLayout(new BoxLayout(panelok,BoxLayout.LINE_AXIS ));
					
					//Crée et ajoute le boutthon OK.
					panelok.add(add = new JButton("OK"));
					
					
					// L'action du boutton est envoyer au server les information qu'il y a dans chaque
					// champ de texte afin de ajouter une video à liste de fichiers multimedia.
					// Au-délà, il envoie la message au client: "The video was added" si tout se passe bien ou
					// "Error! The video was not added" cas contraire.
					add.addActionListener(new ActionListener(){
						public void actionPerformed(ActionEvent e){
							
							String name = fieldName.getText();
							String pathName = fieldPath.getText();
							String duration = fieldDuration.getText();
							
							if(name.length() == 0 || pathName.length() == 0 || duration.length() == 0 )
								JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any fields are empty.","Error Message",JOptionPane.ERROR_MESSAGE);
							
							else
							{
							// Envoie la request 5 afin d'entrer à l'option 5(5 - Add a video)
							// du server.
							Client.sendRequest("5");
							
							// Preparation de la request à être envoyée.
							String request = fieldName.getText() + ";" + fieldPath.getText() + ";" + fieldDuration.getText();
							
							//Prend la reponse du server.
							String response = Client.sendRequest(request) + "\n" ;
							
							// Envoie la message au client.
							JOptionPane.showMessageDialog(new JFrame(),response);
							
							// Envoie l'option "return" du server afin de returner au menu principal.
							Client.sendRequest("return");
							
							// Ferme la fenêtre add video.
							addVideo.dispose();
							}
						}
					});
					
					JPanel panel = new JPanel();
					panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
					panel.add(panelName);
					panel.add(panelPath);
					panel.add(panelDuration);
					panel.add(panelok);
					
					//Configuration de la fenêtre add video.
					addVideo.setTitle("Add Video");
					addVideo.setLocationRelativeTo(null);
					
					addVideo.getContentPane().add(panel);
					addVideo.pack();
					addVideo.setVisible(true);
				}
				
				
				else if ( e.getActionCommand() == "Add Film")
				{
					//Crée une nouvelle fenêtre.
					final JFrame addFilm =  new JFrame();
					JButton add;
					final JTextField fieldName;
					final JTextField fieldPath;
					final JTextField fieldDuration;
					final JTextField fieldChapter;
				
					
					JPanel panelName = new JPanel();
					
					
					//Ajoute une label et un champ de texte pour nom du fichier.
					panelName.add(new JLabel("   File name:"));
					panelName.add( fieldName = new JTextField(30));
					
				    
					JPanel panelPath = new JPanel();
					
					//Ajoute une label et un champ de texte pour chemin d'accès à un fichier film.
					panelPath.add(new JLabel(" Path name:"));
					panelPath.add( fieldPath = new JTextField(30));
					
			
					JPanel panelDuration = new JPanel();	
					
					//Ajoute une label et un champ de texte pour la durée integrale d'un film.
					panelDuration.add(new JLabel("     Duration:"));
					panelDuration.add( fieldDuration = new JTextField(30));
		
					
					JPanel panelChapter = new JPanel();
					
					// Ajoute une label et un champ de texte pour le nombre de chapitres d'un film.
					panelChapter.add(new JLabel("N°Chapters:"));
					panelChapter.add( fieldChapter = new JTextField(30));
				
					
					JPanel panelok = new JPanel();
					panelok.setLayout(new BoxLayout(panelok,BoxLayout.LINE_AXIS ));
					
					//Crée et ajoute le boutthon OK.
					panelok.add(add = new JButton("OK"));
					
					
					// L'action du boutton est envoyer au server les information qu'il y a dans chaque
					// champ de texte afin de ajouter un film  à liste de fichiers multimedia.
					// Au-délà, il envoie la message au client: "The film was added" si tout se passe bien ou
					// "Error! The film was not added" cas contraire.
					add.addActionListener(new ActionListener(){
						public void actionPerformed(ActionEvent e){
							
							String name = fieldName.getText();
							String pathName = fieldPath.getText();
							String duration = fieldDuration.getText();
							String chapter = fieldChapter.getText();
							
							if(name.length() == 0 || pathName.length() == 0 || duration.length() == 0 || chapter.length() == 0)
								JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any fields are empty.","Error Message",JOptionPane.ERROR_MESSAGE);
							
							
							else
							{
								// Envoie la request 6 afin d'entrer à l'option 6(6 - Add a film)
								// du server.
								Client.sendRequest("6");
								
								// Preparation de la request à être envoyée.
								String request = fieldName.getText() + ";" + fieldPath.getText() + ";" + fieldDuration.getText() + ";" + fieldChapter.getText();
								
								//Prend la reponse du server.
								String response = Client.sendRequest(request) + "\n" ;
								
								// Envoie la message au client.
								JOptionPane.showMessageDialog(new JFrame(),response);
								
								// Envoie l'option "return" du server afin de returner au menu principal.
								Client.sendRequest("return");
								
								// Ferme la fenêtre add film.
								addFilm.dispose();
							}
						}
					});
					
					JPanel panel = new JPanel();
					panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
					panel.add(panelName);
					panel.add(panelPath);
					panel.add(panelDuration);
					panel.add(panelChapter);
					panel.add(panelok);
					
					
					//Configuration de la fenêtre add Film.
					addFilm.setTitle("Add Film");
					addFilm.setLocationRelativeTo(null);
					
					addFilm.getContentPane().add(panel);
					addFilm.pack();
					addFilm.setVisible(true);
				}
				
				
				else if ( e.getActionCommand() == "Delete File")
				{
					//Crée une nouvelle fenêtre.
					final JFrame deleteFile =  new JFrame();
					JButton delete;
					final JTextField fieldName;
					
					JPanel panelName = new JPanel();
					
					//Ajoute une label et un champ de texte pour nom du fichier.
					panelName.add(new JLabel("File name:"));
					panelName.add( fieldName = new JTextField(30));
					
					
					JPanel panelDelete = new JPanel();
					panelDelete.setLayout(new BoxLayout(panelDelete,BoxLayout.LINE_AXIS ));
					
					//Crée et ajoute le boutthon delete.
					panelDelete.add( delete = new JButton("Delete"));
					
					
					// L'action du boutton est supprimer un fichier multimedia de la liste multimedia
					// à partir du nom du fichier.
					// Au-délà, il envoie la message suivante au client: "The file  was deleted" si tout se passe bien 
					// au supprimer un fichier ou "The file  was not deleted", cas contraire.
					delete.addActionListener(new ActionListener(){
						public void actionPerformed(ActionEvent e){
							
							String name = fieldName.getText();
							
							if(name.length() != 0)
							{
								// Envoie la request au server et obtient la reponse.
								String response = Client.sendRequest("delete+" + fieldName.getText());
								
								// Envoie la message au client.
								JOptionPane.showMessageDialog(new JFrame(),response);
								
								// Ferme la fenêtre deleteFile.
								deleteFile.dispose();
							}
							else
								JOptionPane.showMessageDialog(new JFrame(), "Field empty! Check if any field is empty.","Error Message",JOptionPane.ERROR_MESSAGE);
													
						}
					});
					
					JPanel panel = new JPanel();
					panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
					panel.add(panelName);
					panel.add(panelDelete);
					
					//Configuration de la fenêtre Delete a file.
					deleteFile.setTitle("Delete File");
					deleteFile.setLocationRelativeTo(null);
					
					deleteFile.getContentPane().add(panel);
					deleteFile.pack();
					deleteFile.setVisible(true);
				}
		
		}
		
	}
}
