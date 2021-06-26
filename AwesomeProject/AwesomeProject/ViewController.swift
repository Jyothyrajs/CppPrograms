//
//  ViewController.swift
//  AwesomeProject
//
//  Created by AntScript on 2019/12/30.
//  Copyright © 2019 happycoding. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

	fileprivate let logoImageView	= UIImageView()
	fileprivate let helloLabel		= UILabel()

	override func viewDidLoad() {
		super.viewDidLoad()

		setupUI()
	}

	fileprivate func setupUI() {

//		Assets helper usage: UIImage.assets_hello
		logoImageView.image = UIImage.assets_hello
		view.addSubview(logoImageView)
		logoImageView.translatesAutoresizingMaskIntoConstraints = false
		view.addConstraint(NSLayoutConstraint(item: logoImageView, attribute: .centerX, relatedBy: .equal, toItem: view, attribute: .centerX, multiplier: 1, constant: 0))
		view.addConstraint(NSLayoutConstraint(item: logoImageView, attribute: .centerY, relatedBy: .equal, toItem: view, attribute: .centerY, multiplier: 1, constant: 0))
		view.addConstraint(NSLayoutConstraint(item: logoImageView, attribute: .width, relatedBy: .equal, toItem: logoImageView, attribute: .width, multiplier: 0, constant: 44))
		view.addConstraint(NSLayoutConstraint(item: logoImageView, attribute: .height, relatedBy: .equal, toItem: logoImageView, attribute: .height, multiplier: 0, constant: 44))

//		Localization helper usage: String.localized_helloWorld
		helloLabel.text = String.localized_helloWorld
		helloLabel.textAlignment = .center
		view.addSubview(helloLabel)
		helloLabel.translatesAutoresizingMaskIntoConstraints = false
		view.addConstraint(NSLayoutConstraint(item: helloLabel, attribute: .top, relatedBy: .equal, toItem: logoImageView, attribute: .bottom, multiplier: 1, constant: 44))
		view.addConstraint(NSLayoutConstraint(item: helloLabel, attribute: .leading, relatedBy: .equal, toItem: view, attribute: .leading, multiplier: 1, constant: 0))
		view.addConstraint(NSLayoutConstraint(item: helloLabel, attribute: .trailing, relatedBy: .equal, toItem: view, attribute: .trailing, multiplier: 1, constant: 0))
		view.addConstraint(NSLayoutConstraint(item: helloLabel, attribute: .height, relatedBy: .equal, toItem: helloLabel, attribute: .height, multiplier: 1, constant: 0))
		
	}


}

