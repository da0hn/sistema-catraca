package br.edu.ifmt.catracacontrol.views;

import br.edu.ifmt.catracacontrol.controllers.TransferDataController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.io.IOException;

public class TransferDataView extends Application {
  @Override public void start(Stage stage) throws Exception {
    try {
      var view = new FXMLLoader();
      Parent parent = view.load(getClass().getResourceAsStream("/views/transfer_data.fxml"));
      parent.getStylesheets().add(getClass().getResource("/css/style.css").toExternalForm());
      TransferDataController controller = view.getController();
      controller.setStage(stage);
      stage.setScene(new Scene(parent));
      stage.setTitle("CATRACA $YSTEM");
      stage.setResizable(false);
      stage.getIcons().add(
        new Image(this.getClass().getResourceAsStream("/images/ticket_gate.png"))
      );
      stage.show();
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }
}
