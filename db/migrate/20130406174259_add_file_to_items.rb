class AddFileToItems < ActiveRecord::Migration
  def change
    add_column :items, :file, :string
  end
end
